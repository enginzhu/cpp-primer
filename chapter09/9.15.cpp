#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

bool compareVector(const vector<int> &vec1, const vector<int> &vec2)
{
	if (vec1.size() != vec2.size())
	{
		return false;
	}
	vector<int>::const_iterator iter1, iter2;
	for (iter1 = vec1.cbegin(), iter2 = vec2.cbegin(); iter1 != vec1.cend(); ++iter1, ++iter2)
	{
		if (*iter1 != *iter2)
		{
			return false;
		}
	}
	return true;
}

int main(int argc, char* argv[])
{
	vector<int> vec1{1, 2, 3};
	vector<int> vec2{1, 2, 3};
	vector<int> vec3{1, 2};
	vector<int> vec4{1, 2, 4};
	bool ret1 = compareVector(vec1, vec2);
	bool ret2 = compareVector(vec1, vec3);
	bool ret3 = compareVector(vec1, vec4);

	cout << ret1 << ret2 << ret3 << endl;
	cout << vec1.capacity() << endl;
}
