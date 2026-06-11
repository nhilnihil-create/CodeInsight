#include <bits/stdc++.h>
using namespace std;

int p[30];
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	
	memset(p, -1, sizeof(p));
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (p[s[i] - 'a'] != -1) {
			int len = i - p[s[i] - 'a'] + 1;
			if (2 * 2 > len) {
				cout << p[s[i] - 'a']+1 << " " << i+1 << '\n';
				return 0;
			}
		}
		p[s[i] - 'a'] = i;
	}
	cout << "-1 -1\n";

	return 0;
}