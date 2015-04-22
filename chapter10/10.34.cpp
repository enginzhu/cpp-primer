#include <iostream>
#include <iterator>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


int main(int argc, char* argv[])
{
	vector<int> ivec = {1, 2, 3, 4, 5};
	vector<int>::const_reverse_iterator iter;
	for (iter = ivec.crbegin(); iter != ivec.crend(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}
