//
// result:double free or corruption (out): 0x000000000129c020
// sp is a smart pointer, which will call delete automatically at the end
// of the block. However, we call the delete explicitly, that's why the double 
// free happened.
//


#include <iostream>
#include <memory>

using std::shared_ptr;
using std::make_shared;

int main()
{
	auto sp = make_shared<int>();
	auto p = sp.get();
	delete p;
}
