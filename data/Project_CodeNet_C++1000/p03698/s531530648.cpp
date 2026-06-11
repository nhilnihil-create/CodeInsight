#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(void) {
	string S;
	cin >> S;
	string ans = "yes";
	set<char> c;
	for (int i = 0; i < S.length(); i++) {
		if (!c.insert(S[i]).second) ans = "no";
	}
	cout << ans << "\n";
	return 0;
}
