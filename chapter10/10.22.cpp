#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::count_if;
using std::bind;
using namespace std::placeholders;

bool isWordLengthMoreThanGivenSize(const string &word, int size)
{
	return word.size() >= size;
}

int main(int argc, char* argv[])
{
	vector<string> svec = {"12", "12345", "1234", "1234", "123"};
	auto count = count_if(svec.cbegin(), svec.cend(), bind(isWordLengthMoreThanGivenSize, _1, 4));
	cout << count << endl;
}
