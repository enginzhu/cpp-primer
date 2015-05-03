#include "12.19.h"
#include <iostream>

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

int main()
{
	StrBlob b{"hello", "chu"};
	std::cout << b.begin().deref() << std::endl;
}
