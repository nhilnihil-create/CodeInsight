#include<bits/stdc++.h>
using namespace std;

int main() {
	multiset<string> s;
	int n, l;
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		string k;
		cin >> k;
		s.insert(k);
	}

	string ans;
	for (auto x : s) {
		ans = ans + x;
	}

	cout << ans << endl;

}