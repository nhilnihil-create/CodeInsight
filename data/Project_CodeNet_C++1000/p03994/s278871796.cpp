#include <bits/stdc++.h>
using namespace std;

string s;
int n, k;

int main() {
	cin >> s >> k;
	n = s.size();
	for (int i = 0; i < n - 1; i++) {
		int x = ('z' - s[i] + 1) % 26;
		if (x <= k) {
			s[i] = 'a';
			k -= x;
		}
	}
	s[n - 1] = 'a' + ((s[n - 1] - 'a') + k) % 26;
	cout << s << endl;
}
