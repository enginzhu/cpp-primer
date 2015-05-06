#include "12.27.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::ostream;
using std::ifstream;
using std::istringstream;
using std::cin;
using std::cout;
using std::endl;
using std::getline;


TextQuery::TextQuery(ifstream &file):input(new vector<string>)
{
	string line;
	lineNumberType curLine = 0;
	while (getline(file, line))
	{
		input->push_back(line);
		istringstream iss(line);
		string word;
		while (iss >> word)
		{
			auto &lineNumbers = result[word];
			if (!lineNumbers) lineNumbers.reset(new set<lineNumberType>);
			lineNumbers->insert(curLine);
		}
		++curLine;
	}
}

QueryResult TextQuery::query(const string &word) const
{
	static shared_ptr<set<lineNumberType>> emptySet(new set<lineNumberType>);
	auto ret = result.find(word);
	if (ret == result.end())
	{
		return QueryResult(word, emptySet, input);
	}
	return QueryResult(word, ret->second, input);
}


ostream& print(ostream& out, const QueryResult& ret)
{
	out << ret.word << " appears " << ret.numbers->size() << " times " << endl;
	for (auto i : *ret.numbers)
	{
		out << "\tline " << i + 1 << " " << ret.input->at(i) << endl;
	}
	return out;
}


void runQuery(ifstream &infile)
{
	TextQuery tq(infile);
	while (true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) ||  s == "q") break;
		print (cout, tq.query(s)) << endl;
	}
}


int main()
{
	ifstream file("12.27.input");
	runQuery(file);
	return 0;
}
