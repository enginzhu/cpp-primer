#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	int counter = 3;
	auto lambda = [counter]() mutable -> bool {
		if (counter > 0)
		{
			--counter;
		}
		return (counter == 0);
	};

	cout << lambda() << endl;
	cout << lambda() << endl;
	cout << lambda() << endl;
	cout << lambda() << endl;
}
