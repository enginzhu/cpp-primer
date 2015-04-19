#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	int captured = 10;
	auto lambda = [captured](int param)
	{
		return captured + param;
	};
	int argument = 20;
	int sum = lambda(argument);
	cout << sum << endl;
}
