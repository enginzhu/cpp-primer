#include "12.2.h"
#include <iostream>

int main()
{
	const strBlob csb{"hello", "chu"};
	std::cout << csb.front() << " " << csb.back() << std::endl;

	strBlob sb{"hello", "shane"};
	strBlob sb2 = sb;
	std::cout << sb2.use_count() << std::endl;
	sb.back() = "shanechu";
	std::cout << sb.front() << " " << sb.back() << std::endl;
	std::cout << sb2.front() << " " << sb2.back() << std::endl;
}
