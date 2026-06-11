#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
string s;
int f[N], lst[26], nxt[N][26];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s; n = s.size();
	for (int i = 0; i < 26; ++i) lst[i] = nxt[n][i] = n;
	for (int i = n - 1; i >= 0; --i) {
		lst[s[i] - 'a'] = i;
		for (int j = 0; j < 26; ++j) nxt[i][j] = lst[j];
	}
	for (int i = n; i >= 0; --i) {
		f[i] = N;
		for (int j = 0; j < 26; ++j) f[i] = min(f[i], f[nxt[i][j] + 1] + 1);
	} 
	int ptr = 0;
	for (int i = 1; i <= f[0]; ++i) {
		for (int j = 0; j < 26; ++j) {
			int nptr = nxt[ptr][j] + 1;
			if (f[nptr] + 1 == f[ptr]) {
				cout << (char)(j + 'a');
				ptr = nptr;
				break;
			} 
		}
	}
}