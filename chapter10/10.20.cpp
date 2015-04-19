#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::count_if;

int main(int argc, char* argv[])
{
	vector<string> svec = {"the", "quick", "red", "fox", "jumps", "over"};
	auto count = count_if(svec.begin(), svec.end(), [=](const string &str) -> bool
	{
		return str.size() >= 4;
	});
	cout << count << endl;
}
