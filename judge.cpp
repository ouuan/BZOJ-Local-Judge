// judge <problemid> [timeLimit [memoryLimit [checkerPath]]]

#include <algorithm>
#include <windows.h>
#include <iostream>
#include <direct.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <io.h>
#include <map>

using namespace std;

string quote(const string & s)
{
    return "\"" + s + "\"";
}

void unzip(const string & id, const string & path)
{
    ifstream config("config.ini");
    string command;
    getline(config, command);
    getline(config, command);
    getline(config, command);
    getline(config, command, ' ');
    getline(config, command);
    int p = command.find("<id>");
    while (p < command.size())
    {
        command.replace(p, 4, id);
        p = command.find("<id>");
    }
    p = command.find("<path>");
    while (p < command.size())
    {
        command.replace(p, 6, path);
        p = command.find("<path>");
    }
    system(command.c_str());
}

void download(const string & id, const string & path)
{
    ifstream config("config.ini");
    string command;
    getline(config, command);
    getline(config, command);
    getline(config, command);
    getline(config, command);
    getline(config, command, ' ');
    getline(config, command);
    int p = command.find("<id>");
    while (p < command.size())
    {
        command.replace(p, 4, id);
        p = command.find("<id>");
    }
    p = command.find("<path>");
    while (p < command.size())
    {
        command.replace(p, 6, path);
        p = command.find("<path>");
    }
    system(command.c_str());
}

const char RESULT[5][20] = {"Accepted", "Wrong Answer", "Time Limit Exceed", "Memory Limit Exceed", "Runtime Error"};

struct Result
{
    int resultid, timeUsed, memoryUsed;
};

string problemid, checker, timeLimit, memoryLimit;
map<string, Result> result;
int totalTime, maxTime, maxMemory, accepted;

int main(int argc, char* argv[])
{
    if (argc < 2 || argc > 5)
    {
        puts("judge <problemid> [timeLimit [memoryLimit [checkerPath]]]");
        return 1;
    }

    problemid = argv[1];

    if (argc <= 3)
    {
        string s;
        ifstream config("config.ini");
        config >> s >> timeLimit;
        config >> s >> memoryLimit;
        config.close();
    }

    if (argc >= 3) timeLimit = argv[2];

    if (argc >= 4) memoryLimit = argv[3];

    string pwd = getcwd(NULL, 0);
    string path = pwd + "\\data\\" + problemid;

    if (argc >= 5)
    {
        checker = argv[4];
        if (checker == "1")
        {
            if (system(("compile " + quote(pwd + "\\problems\\" + problemid + "\\checker") + " " + quote(" -I \\\"" + pwd + "\\\"")).c_str()))
            {
                puts("Checker Compile Error!");
                return 1;
            }
            checker = pwd + "\\problems\\" + problemid + "\\checker.exe";
        }
        checker = quote(checker);
    }

    if (system(("compile " + quote(pwd + "\\problems\\" + problemid + "\\" + problemid)).c_str()))
    {
        puts("Compile Error!");
        return 1;
    }

    if (_access(path.c_str(), 0) == -1)
    {
        path += ".zip";
        if (_access(path.c_str(), 0) == -1)
        {
            puts("downloading...");
            download(problemid, quote(pwd + "\\data"));
        }
        while (_access(path.c_str(), 0) == -1);
        Sleep(100);
        puts("unzipping...");
        unzip(problemid, pwd + "\\data");
        while (_access((pwd + "\\data\\" + problemid).c_str(), 0) == -1);
    }

    path = pwd + "\\data\\" + problemid + "\\*.in";

    intptr_t handle;
    _finddata_t findData;

    handle = _findfirst(path.c_str(), &findData);
    if (handle == -1)
    {
        puts("No data found!");
        return 1;
    }

    string executableFile = pwd + "\\problems\\" + problemid + "\\" + problemid + ".exe";

    do
    {
        if (!(findData.attrib & _A_SUBDIR && strcmp(findData.name, ".") == 0 && strcmp(findData.name, "..") == 0))
        {
            string name = findData.name;
            int p = name.rfind(".");
            name = name.substr(0, p);
            string inpath = pwd + "\\data\\" + problemid + "\\" + name + ".in";
            string outpath = pwd + "\\problems\\" + problemid + "\\" + name + ".out";
            string anspath = pwd + "\\data\\" + problemid + "\\" + name + ".out";
            if (_access(anspath.c_str(), 0) == -1)
            {
                anspath = pwd + "\\data\\" + problemid + "\\" + name + ".ans";
                if (_access(anspath.c_str(), 0) == -1)
                {
                    cout << "Please enter answer file suffix for the test point " << name << ": ";
                    string ans_suffix;
                    cin >> ans_suffix;
                    anspath = pwd + "\\data\\" + problemid + "\\" + name + "." + ans_suffix;
                    if (_access(anspath.c_str(), 0) == -1)
                    {
                        cout << "Unable to find the answer file for the test point " + name << endl;
                        continue;
                    }
                }
            }
            system(("judger " + quote(executableFile) + " " + quote(inpath) + " " + quote(outpath) + " " + quote(anspath)
                    + " " + quote(timeLimit) + " " + quote(memoryLimit) + " " + checker).c_str());
            ifstream res("judger.out");
            int t;
            res >> t;
            result[name].resultid = t;
            if (!t) ++accepted;
            res >> t;
            result[name].timeUsed = t;
            totalTime += t;
            maxTime = max(maxTime, t);
            res >> t;
            result[name].memoryUsed = t;
            maxMemory = max(maxMemory, t);
            res.close();
            remove("judger.out");
        }
    } while (_findnext(handle, &findData) == 0);

    path = pwd + "\\problems\\" + problemid + "\\judge.out";

    ofstream res(path);

    res.setf(ios_base::fixed);
    res.precision(2);

    res << "Tests: " << accepted << " / " << result.size() << endl;
    res << "maxTime: " << maxTime / 1000.0 << " s" << endl;
    res << "totalTime: " << totalTime / 1000.0 << " s" << endl;
    res << "maxMemory: " << maxMemory / 1024.0 / 1024 << " MiB" << endl;

    for (auto k : result)
    {
        res << endl;
        res << "Test " << k.first << endl;
        res << "result: " << RESULT[k.second.resultid] << endl;
        res << "timeUsed: " << k.second.timeUsed / 1000.0 << " s" << endl;
        res << "memoryUsed: " << k.second.memoryUsed / 1024.0 / 1024 << " MiB" << endl;
    }

    res.close();

    system(quote(path).c_str());

    return 0;
}
