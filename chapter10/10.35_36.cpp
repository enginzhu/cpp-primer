#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::find;


int main(int argc, char* argv[])
{
	vector<int> ivec = {1, 2, 3, 4, 5};
	for (auto iter = ivec.cend() - 1; true; iter--)
	{
		cout << *iter << " ";
		if (iter == ivec.cbegin()) break;
	}
	cout << endl;

	vector<int> vec = {1 ,0, 2, 0, 3, 0, 4};
	auto iter0 = find(vec.crbegin(), vec.crend(), 0);
	auto index = std::distance(iter0, vec.crend());
	cout << index << endl;
}
