// opendir <problemid>

#include <direct.h>
#include <cstdlib>
#include <string>

using namespace std;

string quote(const string & s)
{
    return "\"" + s + "\"";
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        puts("opendir <problemid>");
        return 1;
    }

    string problemid = argv[1];
    string pwd = getcwd(NULL, 0);
    string path = quote(pwd + "\\problems\\" + problemid);

    if (_access(path.c_str(), 0) == -1) system(("mkdir " + path).c_str());

    system(("start \"\" " + path).c_str());

    return 0;
}
