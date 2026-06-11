#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	char a, b, c;
	a = (int)s1.at(0) - 32;
	b = (int)s2.at(0) - 32;
	c = (int)s3.at(0) - 32;

	cout << a << b << c << endl;
}