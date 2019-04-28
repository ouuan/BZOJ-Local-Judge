// open <problemid> [type = 1]
// type = 1 to open problem, type = 2 to open data

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

void unzip(const string & ZIPpath, const string & unZIPpath)
{
    ifstream config("config.txt");
    string command;
    getline(config, command);
    getline(config, command);
    getline(config, command);
    getline(config, command, ' ');
    getline(config, command);
    int p = command.find("<ZIPpath>");
    while (p < command.size())
    {
        command.replace(p, 9, ZIPpath);
        p = command.find("<ZIPpath>");
    }
    p = command.find("<unZIPpath>");
    while (p < command.size())
    {
        command.replace(p, 11, unZIPpath);
        p = command.find("<unZIPpath>");
    }
    system(command.c_str());
}

void download(const string & link, const string & path, const string & name)
{
    ifstream config("config.txt");
    string command;
    getline(config, command);
    getline(config, command);
    getline(config, command);
    getline(config, command);
    getline(config, command, ' ');
    getline(config, command);
    int p = command.find("<link>");
    while (p < command.size())
    {
        command.replace(p, 6, link);
        p = command.find("<link>");
    }
    p = command.find("<path>");
    while (p < command.size())
    {
        command.replace(p, 6, path);
        p = command.find("<path>");
    }
    p = command.find("<name>");
    while (p < command.size())
    {
        command.replace(p, 6, name);
        p = command.find("<name>");
    }
    system(command.c_str());
}

int main(int argc, char* argv[])
{
    if (argc < 2 || argc > 3)
    {
        puts("open <problemid> [type = 1]");
        return 1;
    }

    string problemid = argv[1];
    string pwd = getcwd(NULL, 0);

    if (argc == 2 || atoi(argv[2]) == 1) system(("start " + pwd + "\\problems\\" + problemid).c_str());
    else
    {
        string path = pwd + "\\data\\" + problemid;
        if (_access(path.c_str(), 0) == -1)
        {
            path += ".zip";
            if (_access(path.c_str(), 0) == -1)
            {
                puts("downloading...");
                download("https://lydsy.download/archive/" + problemid + ".zip", quote(pwd + "\\data"), problemid + ".zip");
            }
            while (_access(path.c_str(), 0) == -1);
            puts("unzipping...");
            unzip(quote(path), quote(pwd + "\\data"));
            while (_access((pwd + "\\data\\" + problemid).c_str(), 0) == -1);
        }
        system(("start " + pwd + "\\data\\" + problemid).c_str());
    }

    return 0;
}
