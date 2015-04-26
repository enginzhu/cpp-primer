#include <iostream>
#include <utility>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::pair;

int main (int argc, char* argv[])
{
	vector<pair<string, int>> pvec;
	pair<string, int> p;
	string str;
	int i;
	while ([&]() -> bool
	{
		cout << "please enter a string:" << endl;
		return cin >> str;
	}())
	{
		cout << "please enter a integer:" << endl;
		cin >> i;
		p = make_pair(str, i);
		pvec.push_back(p);
	}

	for (const auto &pa : pvec)
	{
		cout << pa.first << " " << pa.second << endl;
	}
}
