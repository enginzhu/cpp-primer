#include <iostream>


using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	auto f = [](int a, int b)
	{
		return a + b;
	};

	int sum = f(1, 2);
	cout << sum << endl;
}
