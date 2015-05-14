#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::size_t;

class HasPtr
{
public:
	friend void printUse(const HasPtr&);
	HasPtr(const string& s = string()) : ps(new string(s)), i(0), use(new size_t(1)) { }
	HasPtr(const HasPtr& hp) : ps(hp.ps), i(hp.i), use(hp.use) { ++*use; }
	HasPtr& operator=(const HasPtr&);
	~HasPtr();
private:
	string *ps;
	int i;
	size_t *use;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	++*rhs.use;
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

HasPtr::~HasPtr()
{
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}
}

void printUse(const HasPtr& ptr)
{
	cout << *ptr.ps << " has " << *ptr.use << " references" << endl;
}

int main()
{
	HasPtr p("helo");
	cout << "HasPtr p(\"helo\")" << endl;
	printUse(p);
	
	{
		HasPtr p2(p);
		cout << "HasPtr p2(p)" << endl;
		printUse(p2);
	
		p = p;
		cout << "HasPtr p = p" << endl;
		printUse(p);

		p = p2;
		cout << "HasPtr p = p2" << endl;
		printUse(p);
		printUse(p2);
	}

	printUse(p);

}
