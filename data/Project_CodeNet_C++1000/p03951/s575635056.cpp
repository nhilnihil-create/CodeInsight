#include<bits/stdc++.h>
using namespace std;

int main() {	
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;


	for (int i = 0; i < n; ++i) {
		bool ok = true;
		for (int j = i; j < n; j++) {
			if (s[j] != t[j - i]) {
				ok = false;
			}
		}
		if (ok) {
			cout << max(n, n + i) << endl;
			return 0;
		}
	}

	cout << n + n << endl;
	return 0;
}
