#include<iostream>
#include<string>
using namespace std;
int main() {
	string a, b, c;
	cin >> a >> b >> c;
	a[0] = a[0] - 'a' + 'A';
	b[0] = b[0] - 'a' + 'A';
	c[0] = c[0] - 'a' + 'A';
	cout << a[0] << b[0] << c[0] << endl;
	return 0;
}