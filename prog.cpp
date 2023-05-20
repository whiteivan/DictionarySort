#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::cerr;

int main(int argc, char* argv[])
{
	ifstream inFile(argv[1]);
	vector<string> dataBase;
	string line;
	while (getline(inFile, line))
	{
		dataBase.push_back(line);
	}

	return 0;
}