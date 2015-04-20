#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::getline;
using std::ifstream;


vector<string> readLinesFromFileIntoVector(const string &filename)
{
	ifstream file(filename);
	vector<string> svec;
	string line;
	while (getline(file, line))
	{
		svec.push_back(line);
	}
	return svec;
}

int main(int argc, char* argv[])
{
	vector<string> lines = readLinesFromFileIntoVector("8.4.text");
	for (auto &line : lines)
	{
		cout << line << endl;
	}
}
