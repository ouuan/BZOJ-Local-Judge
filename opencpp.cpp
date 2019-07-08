// opencpp <problemid>

#include <direct.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <io.h>

using namespace std;

string quote(const string & s)
{
    return "\"" + s + "\"";
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        puts("opencpp <problemid>");
        return 1;
    }

    string problemid = argv[1];
    string pwd = getcwd(NULL, 0);
    string path = pwd + "\\problems\\" + problemid; 

    if (_access(path.c_str(), 0) == -1)
    {
        system(("mkdir " + quote(path)).c_str());
    }

    path += "\\" + problemid + ".cpp";
    
    ifstream config("config.ini");
    string s;
    getline(config, s);
    getline(config, s);
    getline(config, s);
    getline(config, s);
    getline(config, s);
    getline(config, s, ' ');
    getline(config, s);

    if (_access(path.c_str(), 0) == -1)
    {
        system(("copy " + quote(s) + " " + quote(path)).c_str());
    }

    system(("start \"\" " + quote(path)).c_str());

    return 0;
}
