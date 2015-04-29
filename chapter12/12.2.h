#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>

using std::vector;
using std::string;
using std::initializer_list;
using std::shared_ptr;
using std::make_shared;

class strBlob
{
public:
	using size_type = vector<string>::size_type;
	strBlob():data(make_shared<vector<string>>()){};
	strBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)){};
	
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	int use_count() const { return data.use_count(); }
	void push_back(const string &t) { data->push_back(t); }
	void pop_back()
	{
		check_size(0, "pop_back on empty strBlob");
		data->pop_back();
	}
	string& front()
	{
		check_size(0, "front on empty strBlob");
		return data->front();
	}
	string& back()
	{
		check_size(0, "back on empty strBlob");
		return data->back();
	}
	const string& front() const
	{
		check_size(0, "front on empty strBlob");
		return data->front();
	}
	const string& back() const
	{
		check_size(0, "back on empty strBlob");
		return data->back();
	}
private:
	shared_ptr<vector<string>> data;
	void check_size(size_type i, const string &msg) const
	{
		if (i >= data->size()) throw std::out_of_range(msg);
	};
};
