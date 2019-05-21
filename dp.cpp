// dp <problemid> [generateCommand [checkerPath]]

#include <cstdio>
#include <string>
#include <cstdlib>
#include <direct.h>

using namespace std;

string quote(const string & s)
{
    return "\"" + s + "\"";
}

string problemid, generateCommand, checkerPath;
bool hasChecker;

int main(int argc, char* argv[])
{
    if (argc < 2 || argc > 4)
    {
        puts("dp <problemid> [generateCommand [checkerPath]]");
        return 0;
    }

    problemid = argv[1];
    string pwd = getcwd(NULL, 0);

    if (argc >= 3) generateCommand = argv[2];
    else
    {
        if (system(("compile " + quote(pwd + "\\problems\\" + problemid + "\\gen")).c_str()))
        {
            puts("Generator Compile Error!");
            return 1;
        }
        generateCommand = "call " + quote(pwd + "\\problems\\" + problemid + "\\gen.exe") +
            " > " + quote(pwd + "\\problems\\" + problemid + "\\dp.in");
    }

    if (argc >= 4)
    {
        hasChecker = true;
        checkerPath = argv[3];
        if (checkerPath == "1")
        {
            if (system(("compile " + quote(pwd + "\\problems\\" + problemid + "\\checker") + " " + quote("-I " + pwd)).c_str()))
            {
                puts("Checker Compile Error!");
                return 1;
            }
            checkerPath = pwd + "\\problems\\" + problemid + "\\checker.exe";
        }
    }

    if (system(("compile " + quote(pwd + "\\problems\\" + problemid + "\\" + problemid)).c_str()))
    {
        puts("Source File Compile Error!");
        return 1;
    }

    if (system(("compile " + quote(pwd + "\\problems\\" + problemid + "\\std")).c_str()))
    {
        puts("Std Compile Error!");
        return 1;
    }

    while (1)
    {
        system(generateCommand.c_str());
        system(("call " + quote(pwd + "\\problems\\" + problemid + "\\" + problemid)
                + " < " + quote(pwd + "\\problems\\" + problemid + "\\dp.in")
                + " > " + quote(pwd + "\\problems\\" + problemid + "\\" + problemid + ".out")).c_str());
        system(("call " + quote(pwd + "\\problems\\" + problemid + "\\std")
                + " < " + quote(pwd + "\\problems\\" + problemid + "\\dp.in")
                + " > " + quote(pwd + "\\problems\\" + problemid + "\\std.out")).c_str());
        if (hasChecker)
        {
            if (system((quote(checkerPath) + " " + quote(pwd + "\\problems\\" + problemid + "\\dp.in")
                        + " " + quote(pwd + "\\problems\\" + problemid + "\\" + problemid + ".out")
                        + " " + quote(pwd + "\\problems\\" + problemid + "\\std.out")).c_str()))
            {
                puts("Crashed!");
                break;
            }
        }
        else
        {
            if (system(("fc /W " + quote(pwd + "\\problems\\" + problemid + "\\" + problemid + ".out")
                        + " " + quote(pwd + "\\problems\\" + problemid + "\\std.out")).c_str()))
            {
                puts("Crashed!");
                break;
            }
        }
    }

    system(quote(pwd + "\\problems\\" + problemid + "\\dp.in").c_str());
    system(quote(pwd + "\\problems\\" + problemid + "\\std.out").c_str());
    system(quote(pwd + "\\problems\\" + problemid + "\\" + problemid + ".out").c_str()); 

    return 0;
}
