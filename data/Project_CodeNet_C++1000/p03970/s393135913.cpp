#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char **argv) {
	string s;
	string s2 = "CODEFESTIVAL2016";
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < 16; ++i) {
		if(s[i] != s2[i]) { cnt ++; }
	}
	cout << cnt << endl;
}
