#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::initializer_list;

class StrBlob
{
public:
	StrBlob() : data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
	StrBlob(const StrBlob& sb)
	{
		data = make_shared<vector<string>>(*sb.data);
	}
	void push_back(const string &s)
	{
		data->push_back(s);
	}
	string& back()
	{
		return data->back();
	}
private:
	shared_ptr<vector<string>> data;
};

int main()
{
	StrBlob sb1{"hi", "string"};
	StrBlob sb2(sb1);
	cout << sb1.back() << endl;
	cout << sb2.back() << endl;

	sb1.push_back("tail");
	cout << sb1.back() << endl;
	cout << sb2.back() << endl;
}
