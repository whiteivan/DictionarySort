#include <iostream>
#include <fstream>
#include <string>
#include <list>

using std::string;
using std::list;
using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::cerr;

list<string> SortD(list<string>& dic)
{
	for (auto i = dic.begin();i != dic.end();i++)
	{
		auto j = ++i;
		--i;
		for (auto a = i->begin(); a!= i -> end(); a++)
		{
			if (i[a]==j[a])
			{
				continue;
			}
			else if (i[a]<j[a])
			{
				break;
			} else
			{
				string temp = *j;
				dic.erase(j);
				dic.insert(i,temp);
				break;
			}
		}
	}
	return dic;
}

int main(int argc, char* argv[])
{
	ifstream inFile(argv[1]);
	list<string> dataBase;
	string line;
	while (getline(inFile, line))
	{
		dataBase.push_back(line);
	}
	list<string> dataSort = SortD(dataBase);
	ofstream outFile(argv[2], ofstream::app);
	for each (auto s in dataSort)
	{
		outFile << s << "\n";
	}
	return 0;
}