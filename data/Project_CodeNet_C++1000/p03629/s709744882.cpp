#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, S = 26;

int n, dist;

int len[N], nxt[N][S];
bool f[S];

int main() {
#ifdef HOME
	freopen("arc081c.in", "r", stdin);
	freopen("arc081c.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string str, ant;

	cin >> str;
	n = str.size();

	for (int ch = 0; ch < S; ++ch)
		nxt[n][ch] = n;
	for (int i = n - 1; i >= 0; --i)
	for (int ch = 0; ch < S; ++ch)
		nxt[i][ch] = (ch + 'a' == str[i] ? i : nxt[i + 1][ch]);

	for (int i = n - 1; i >= 0; --i) {
		if (!f[str[i] - 'a']) {
			f[str[i] - 'a'] = true;
			dist+= 1; }
		len[i] = len[i + 1];
		if (dist == 26) {
			len[i]+= 1;
			memset(f, 0x00, sizeof f);
			dist = 0; } }

	len[n] = len[n + 1] = -1;
	for (int p = -1, need = len[0]; need >= 0; --need) {
		for (int ch = 0; ch < S; ++ch) {
			int tr = nxt[p + 1][ch];
			if (len[tr + 1] < need) {
				ant.push_back(ch + 'a');
				p = tr;
				break; } } }

	cout << ant << endl;

	return 0; }

