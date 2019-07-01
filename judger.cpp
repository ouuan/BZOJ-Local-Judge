/*

judger <executableFile> <inputFile> <outputFile> <answerFile> <timeLimit> <memoryLimit> [checkerPath]

timeLimit: ms
memoryLimit: MiB

resultID:
    - 0 : Accepted
    - 1 : Wrong Answer
    - 2 : Time Limit Exceed
    - 3 : Memory Limit Exceed
    - 4 : Runtime Error

judger.out:

```
resultID
timeUsed
memoryUsed
returnValue
```

*/

#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <csignal>
#include <psapi.h>
#include <cstdio>
#include <string>
#include <ctime>

using namespace std;

string executableFile, inputFile, outputFile, answerFile, checkerPath;
int timeLimit, memoryLimit, returnValue = -1, timeUsed, memoryUsed, resultID; 
bool hasChecker;

void quote(string & s)
{
    s = "\"" + s + "\"";
}

HANDLE hProcess;
bool programIsOpen;

void signalHandler(int signum)
{
    if (programIsOpen) TerminateProcess(hProcess, 0);
    exit(signum);
}

void run()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    SECURITY_ATTRIBUTES sa;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESTDHANDLES;
    ZeroMemory(&pi, sizeof(pi));
    ZeroMemory(&sa, sizeof(sa));
    sa.bInheritHandle = TRUE;

    si.hStdInput = CreateFile(inputFile.c_str(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, 
                              &sa,OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); 

    si.hStdOutput = CreateFile(outputFile.c_str(), GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, 
                               &sa, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    PROCESS_MEMORY_COUNTERS_EX info;
    ZeroMemory(&info, sizeof(info));
    info.cb = sizeof(info);

    FILETIME creationTime, exitTime, kernelTime, userTime;
    SYSTEMTIME realTime;

    int startTime = clock();

    if (!CreateProcess(NULL, (char *)executableFile.c_str(), NULL, NULL, TRUE, HIGH_PRIORITY_CLASS | CREATE_NO_WINDOW, NULL, NULL, &si, &pi))
    {
        return;
    }

    hProcess = pi.hProcess;
    programIsOpen = true;
    signal(SIGINT, signalHandler);

    DWORD dwExitCode;
    do
    {
        GetExitCodeProcess(pi.hProcess, &dwExitCode);
        returnValue = dwExitCode;
        GetProcessTimes(pi.hProcess, &creationTime, &exitTime, &kernelTime, &userTime);
        FileTimeToSystemTime(&userTime, &realTime);
        timeUsed = realTime.wMilliseconds
            + realTime.wSecond * 1000
            + realTime.wMinute * 60 * 1000
            + realTime.wHour * 60 * 60 * 1000;
        GetProcessMemoryInfo(pi.hProcess, (PROCESS_MEMORY_COUNTERS*)&info, sizeof(info));
        memoryUsed = info.PeakWorkingSetSize;
        if (clock() - startTime > timeLimit * 4)
        {
            resultID = 2;
            break;
        }
    } while (returnValue == 259 && memoryUsed <= memoryLimit * 1024 * 1024 * 2 && timeUsed <= timeLimit * 2);

    TerminateProcess(pi.hProcess, 0);
    programIsOpen = false;

    GetProcessTimes(pi.hProcess, &creationTime, &exitTime, &kernelTime, &userTime);
    FileTimeToSystemTime(&userTime, &realTime);
    timeUsed = realTime.wMilliseconds
        + realTime.wSecond * 1000
        + realTime.wMinute * 60 * 1000
        + realTime.wHour * 60 * 60 * 1000;

    GetProcessMemoryInfo(pi.hProcess, (PROCESS_MEMORY_COUNTERS*)&info, sizeof(info));
    memoryUsed = info.PeakWorkingSetSize;

    CloseHandle(pi.hProcess);
    CloseHandle(si.hStdInput);
    CloseHandle(si.hStdOutput);
}

int main(int argc, char* argv[])
{
    if (argc != 7 && argc != 8)
    {
        puts("judger <executableFile> <inputFile> <outputFile> <answerFile> <timeLimit> <memoryLimit> [checker]");
        return 1;
    }

    executableFile = argv[1];
    inputFile = argv[2];
    outputFile = argv[3];
    answerFile = argv[4];
    timeLimit = atoi(argv[5]);
    memoryLimit = atoi(argv[6]);
    if (argc > 7)
    {
        hasChecker = true;
        checkerPath = argv[7];
        quote(checkerPath); 
    }

    run();

    if (resultID == 2 || timeUsed > timeLimit) resultID = 2;
    else if (memoryUsed > memoryLimit * 1024 * 1024) resultID = 3;
    else if (returnValue != 0) resultID = 4;
    else
    {
        string command;
        quote(inputFile);
        quote(outputFile);
        quote(answerFile);
        if (hasChecker) command = "call " + checkerPath + " " + inputFile + " " + outputFile + " " + answerFile; 
        else command = "fc /W " + outputFile + " " + answerFile;
        if (system(command.c_str())) resultID = 1;
        else resultID = 0;
    }

    ofstream fout("judger.out");
    fout << resultID << endl << timeUsed << endl << memoryUsed << endl << returnValue;
    fout.close();

    return 0;
}
