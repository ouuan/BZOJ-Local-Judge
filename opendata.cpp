// opendata <problemid>

#include <windows.h>
#include <direct.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <io.h>

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

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        puts("opendata <problemid>");
        return 1;
    }

    string problemid = argv[1];
    string pwd = getcwd(NULL, 0);

    string path = pwd + "\\data\\" + problemid;
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
    system(("start \"\" " + quote(pwd + "\\data\\" + problemid)).c_str());

    return 0;
}
