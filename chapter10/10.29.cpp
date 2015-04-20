#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>


using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::istream_iterator;
using std::ifstream;


int main (int argc, char* argv[])
{
	ifstream file("10.29.text");
	istream_iterator<string> str_iter(file);
	istream_iterator<string> str_eof;
	vector<string> svec(str_iter, str_eof);
	for (auto &word : svec)
	{
		cout << word << endl;
	}
}
