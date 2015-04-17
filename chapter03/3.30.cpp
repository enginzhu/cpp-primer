#include <iostream>

constexpr size_t array_size = 10;

int main()
{
	int a[array_size];
	for (size_t ix = 1; ix < array_size; ++ix)
	{
		a[ix] = ix;
		std::cout << a[ix] << std::endl;
	}
}
