#include <bits/stdc++.h>
using namespace std;

int n, mod = 1e9 + 7;
string s[2];
int main() {
	cin >> n >> s[0] >> s[1];
	long long rv = 1;
	bool prev = 0; //縦
	for (int i = 0; i < n; i++) {
		if (s[0][i] == s[1][i]) {
			rv *= i ? (prev ? 2 : 1) : 3;
			prev = 1;
		} else {
			rv *= i ? (prev ? 2 : 3) : 6;
			prev = 0;
			i++;
		}
		rv %= mod;
	}
	cout << rv << endl;
}
