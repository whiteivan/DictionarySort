#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

list<string> SortD(list<string>& dic)
{
	for (auto i = dic.begin(); i != dic.end(); ++i)
	{
		for (auto j = std::next(i); j != dic.end(); ++j)
		{
			for (auto a = i->begin(); a != i->end(); ++a)
			{
				for (auto b = j->begin(); b != j->end(); ++b)
				{
					if (*a > *b)
					{
						std::swap(*i, *j);
						break;
					} else if (*a == *b)
					{
						++a;
						continue;
					} else
					{
						break;
					}
				}
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
	ofstream outFile(argv[2]);
	for (const auto& s : dataSort)
	{
		outFile << s << "\n";
	}
	return 0;
}
