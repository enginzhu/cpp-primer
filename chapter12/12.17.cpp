#include <iostream>
#include <memory>

int main()
{
	int ix = 1024,  *pi = &ix, *pi2 = new int(1024);
	typedef std::unique_ptr<int> IntP;

	/**
	 * compile error:ix is not a pointer
	 */
//	IntP p0(ix);
	
	/**
	 * *** Error in `./12.17.out': munmap_chunk(): invalid pointer: 0x00007fff43d02bec ***
	 * attempt to delete a object not allocated using new
	 */
//	IntP p1(pi);

	/**
	 * pi2 will become a dangling pointer at run time
	 */
//	IntP p2(pi2);

	/**
	 * same as p1
	 */
//	IntP p3(&ix);
	
	/**
	 * correct
	 */
//	IntP p4(new int(2048));

	/**
	 * double free or corruption
	 */
//	IntP p2(new int(2048));
//	IntP p5(p2.get());
}
