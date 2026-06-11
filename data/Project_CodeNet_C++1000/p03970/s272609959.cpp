#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	string code = "CODEFESTIVAL2016";
	string s;
	cin >> s;

	int cnt = 0;
	for (int i = 0; i < 16; i++) {
		if (s[i] != code[i]) {
			cnt++;
		}
	}
	
	cout << cnt << endl;
	return 0;
}
