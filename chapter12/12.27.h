#ifndef __12_27_h__
#define __12_27_h__

#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

using std::ifstream;
using std::shared_ptr;
using std::vector;
using std::string;
using std::map;
using std::set;

class QueryResult;
class TextQuery
{
public:
	typedef vector<string>::size_type lineNumberType;
	TextQuery(ifstream&);
	QueryResult query(const string& word) const;
private:
	shared_ptr<vector<string>> input;
	map<string, shared_ptr<set<lineNumberType>>> result;
};

class QueryResult
{
public:
	QueryResult(const string &w, shared_ptr<set<TextQuery::lineNumberType>> set,  shared_ptr<vector<string>> v):
		word(w), numbers(set), input(v) {}
string word;
shared_ptr<vector<string>> input;
shared_ptr<set<TextQuery::lineNumberType>> numbers;
};

#endif
