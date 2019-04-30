// openstatement <problemid>

#include <direct.h>
#include <cstdlib>
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
        puts("openstatement <problemid>");
        return 1;
    }

    string problemid = argv[1];
    string pwd = getcwd(NULL, 0);
    
    system(("start \"\" " + quote(pwd + "\\problems\\" + problemid + "\\" + problemid + ".html")).c_str());

    return 0;
}
