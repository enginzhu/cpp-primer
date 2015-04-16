#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::partition;

bool isWordHas5Chars(const string &word)
{
	return word.size() >= 5;
}

int main(int argc, char* argv[])
{
	vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	auto iter = partition(words.begin(), words.end(), isWordHas5Chars);
	if (iter != words.begin())
	{
		cout << "There is words that equal to or more than 5 characters in the list" << endl;
		words.erase(iter, words.end());
		for (auto const &word : words)
		{
			cout << word << ","	;
		}
		cout << endl;
	}
}
