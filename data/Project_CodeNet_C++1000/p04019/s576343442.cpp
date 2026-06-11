#include <bits/stdc++.h>
#define SZ(v) ((int)((v).size()))
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x=0, y=0;
	string s; cin >> s;
	for (char c : s) {
		if (c == 'N') x |= 1;
		if (c == 'S') x |= 2;
		if (c == 'W') y |= 1;
		if (c == 'E') y |= 2;
	}
	if ((x==0 || x == 3) && (y==0 || y==3)) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}
