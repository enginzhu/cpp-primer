#include <iostream>
#include <deque>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::deque;

int main(int argc, char* argv[])
{
	deque<string> sdeque;
	string word;
	while (cin >> word)
	{
		sdeque.push_back(word);
	}

	deque<string>::const_iterator iter;
	for (iter = sdeque.cbegin(); iter != sdeque.cend(); iter++)
	{
		cout << *iter << ",";
	}
	cout << endl;
}
