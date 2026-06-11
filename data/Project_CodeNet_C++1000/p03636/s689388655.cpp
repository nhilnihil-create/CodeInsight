#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	cin >> a;

	int b = a.size() - 2;
	int c = a.size() - 1;
	cout << a.at(0) << b << a.at(c);
}