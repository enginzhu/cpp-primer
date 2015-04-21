#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::unique_copy;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;


int main(int argc, char* argv[])
{
	istream_iterator<int> i_iter(cin), eof;
	vector<int> ivec;
	unique_copy(i_iter, eof, back_inserter(ivec));
	sort(ivec.begin(), ivec.end());
	ostream_iterator<int> out(cout, " ");
	for (auto &i : ivec)
	{
		*out++ = i;
	}
	cout << endl;
}
