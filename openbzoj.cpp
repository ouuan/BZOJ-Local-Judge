// openbzoj <problemid>

#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		puts("openbzoj <problemid>");
		return 1;
	}
	
	string problemid = argv[1];
	
	system(("start https://www.lydsy.com/JudgeOnline/problem.php?id=" + problemid).c_str());
	
	return 0;
}
