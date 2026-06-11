#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	cout << s[0] << s.length() - 2 << s[s.length() - 1] << "\n";
	return 0;
}
