#include <iostream>
#include <forward_list>

using std::cout;
using std::endl;
using std::forward_list;

int main(int argc, char* argv[])
{
	forward_list<int> flist{1, 2, 3, 4, 6, 7, 8};
	auto prev = flist.before_begin();
	auto cur = flist.begin();
	while (cur != flist.end())
	{
		if (*cur % 2)
		{
			cur = flist.erase_after(prev);
		}
		else
		{
			prev = cur;
			++cur;
		}
	}
	
	for (auto &value : flist)
	{
		cout << value << ",";
	}
	cout << endl;
}
