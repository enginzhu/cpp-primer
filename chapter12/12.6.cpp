#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


vector<int>* factory()
{
	return new vector<int>;
}


void read(vector<int>* ivec)
{
	int i;
	while (cin >> i)
	{
		ivec->push_back(i);
	}
}


void print(vector<int>* ivec)
{
	for (const auto &i : *ivec)
	{
		cout << i << " ";
	}
	cout << endl;
}


int main()
{
	vector<int>* ivec = factory();
	read(ivec);
	print(ivec);
	delete ivec;
	ivec = nullptr;
}
