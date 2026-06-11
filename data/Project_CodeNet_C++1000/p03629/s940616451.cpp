#include <bits/stdc++.h>

const int MAXN = 200010;
int nxt[MAXN][26], f[MAXN], n;
char buf[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> buf + 2; n = strlen(buf + 2);
	f[n + 2] = 1;
	for (int i = n + 1; i; --i) {
		memcpy(nxt[i], nxt[i + 1], 104);
		nxt[i][buf[i + 1] - 'a'] = i + 1;
		f[i] = 0x3f3f3f3f;
		for (int j = 0; j < 26; ++j)
			f[i] = std::min(f[i], f[nxt[i][j]] + 1);
	}
	int x = 1;
	while (x) {
		for (int i = 0; i < 26; ++i) if (f[nxt[x][i]] + 1 == f[x]) {
			std::cout << (char) (i + 'a');
			x = nxt[x][i];
			break;
		}
	}
	std::cout << '\n';
	return 0;
}
