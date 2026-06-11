#include <bits/stdc++.h>
using namespace std;

string a, b, c;
int x, y, z;

int main () {
	cin >> a >> b >> c;
	char s1 = a[0];
	char s2 = b[0];
	char s3 = c[0];
	x = (int)s1 - 32;
	y = (int)s2 - 32;
	z = (int)s3 - 32;
	cout << (char)x << (char)y << (char)z;
}