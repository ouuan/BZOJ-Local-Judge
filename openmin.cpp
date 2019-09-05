// openmin <problemid>

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

string problemid;
map<string, string> res;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        puts("openmin <problemid>");
        return 1;
    }

    problemid = argv[1];

    string pwd = getcwd(NULL, 0);
    string testid, result;

    ifstream resin(pwd + "\\problems\\" + problemid + "\\judge.out");

    getline(resin, result);
    getline(resin, result);
    getline(resin, result);
    getline(resin, result);
    getline(resin, result);

    while (resin >> result)
    {
        resin >> testid >> result;
        resin >> result;
        res[testid] = result;
        getline(resin, result);
        getline(resin, result);
        getline(resin, result);
    }

    intptr_t handle;
    _finddata_t findData;

    handle = _findfirst((pwd + "\\data\\" + problemid + "\\*.in").c_str(), &findData);
    if (handle == -1)
    {
        puts("No data found!");
        return 1;
    }

    unsigned int minSize = 0x7fffffff;
    string minTest;

    do
    {
        if (!(findData.attrib & _A_SUBDIR && strcmp(findData.name, ".") == 0 && strcmp(findData.name, "..") == 0))
        {
            string name = findData.name;
            int p = name.rfind(".");
            name = name.substr(0, p);
            if (res[name] != "Accepted" && findData.size < minSize)
            {
                minSize = findData.size;
                minTest = name;
            }
        }
    } while (_findnext(handle, &findData) == 0);

    if (minTest == "")
    {
        puts("You have already got an AC!");
        return 1;
    }

    system(("opentest " + problemid + " " + minTest).c_str());

    return 0;
}
