#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	string a, b;
	int n;

	a = s[0];
	n = s.size();
	b = s[n - 1];

	cout << a << n-2 << b << endl;
}