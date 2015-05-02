#include <iostream>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

struct connection
{
	string ip;
	int port;
	connection(string _ip, int _port):ip(_ip), port(_port) {}
};

struct destination
{
	string ip;
	int port;
	destination(string _ip, int _port):ip(_ip), port(_port) {}
};

connection connect(destination *d)
{
	shared_ptr<connection> p(new connection(d->ip, d->port));
	cout << "create connection " << p.use_count()  << endl;
	return *p;
}

void disconnect(connection p)
{
	cout << "disconnect connection (" << p.ip << p.port << ")" << endl;
}

void end_connection(connection *p)
{
	disconnect(*p);
}

void f(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c, end_connection);
	cout << "connecting now " << p.use_count() << endl;
}

int main()
{
	destination dest("127.0.0.1", 8000);
	f(dest);
}
