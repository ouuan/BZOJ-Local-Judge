// compile <path> [option]

#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

ifstream config("config.ini");
string command;

int main(int argc, char* argv[])
{
    if (argc < 2 || argc > 3)
    {
        puts("compile <path> [option]");
        return 1;
    }

    int p;

    getline(config, command);
    getline(config, command);
    getline(config, command, ' ');
    getline(config, command);
    config.close();

    p = command.find("<path>");
    while (p < command.size())
    {
        command.replace(p, 6, argv[1]);
        p = command.find("<path>");
    }

    if (argc >= 3) command += argv[2];

    return system(command.c_str());
}
