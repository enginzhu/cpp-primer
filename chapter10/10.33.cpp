#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>


using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::vector;
using std::copy;
using std::back_inserter;


int main(int argc, char* argv[])
{
	ifstream input("10.33.text");
	ofstream odd("10.33.odd.output");
	ofstream even("10.33.even.output");

	istream_iterator<int> int_iter(input), eof;
	vector<int> ivec;
	copy(int_iter, eof, back_inserter(ivec));

	ostream_iterator<int> odd_iter(odd, " ");
	ostream_iterator<int> even_iter(even, "\n");

	for (auto &i : ivec)
	{
		if (i % 2 == 1)
		{
			odd_iter = i;
		}
		else
		{
			even_iter = i;
		}
	}
}
