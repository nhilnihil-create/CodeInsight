#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >>s3;
	char c1, c2, c3;
	c1 = s1.at(0) - 32;
	c2 = s2.at(0) - 32;
	c3 = s3.at(0) - 32;
	cout << c1 << c2 << c3 << endl;
}