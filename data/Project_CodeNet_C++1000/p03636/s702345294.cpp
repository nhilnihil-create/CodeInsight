#include <iostream>
#include <string>

using namespace std;
int main(void)
{
	string a;
	cin >> a;
	char b = a.at(0);
	char c = a[a.size() - 1];
	int s = a.size() - 2;
	cout << b << s << c;
}