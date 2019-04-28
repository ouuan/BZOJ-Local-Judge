//compile <path>

#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

ifstream config("config.txt");
string command;

int main(int argc, char* argv[])
{
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
	
	return system(command.c_str());
}
