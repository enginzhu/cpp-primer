#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct X
{
	X() { cout << "call constructor" << endl; }
	X(const X&) { cout << "call copy constructor" << endl; }
	X& operator=(const X&) { cout << "call copy-assignment constructor" << endl;  }
	~X() { cout << "call destructor" << endl;  }
};

void f(const X &px, X x)
{
	vector<X> vec;
	// It is potentially call the reserve function which causes reallocation 
	// during the execution of push_back. However, reallocation make the elements
	// of the vector itself recall their copy constructor.
	vec.reserve(2);
	vec.push_back(px);
	vec.push_back(x);
}

int main()
{
	X *px = new X;
	f(*px, *px);
}
