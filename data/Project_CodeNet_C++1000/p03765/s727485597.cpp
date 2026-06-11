#include <bits/stdc++.h>

const int N = 100005;
std::string s, t;
int n, m, ss[N], tt[N], q;
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> s >> t >> q, n = s.size(), m = t.size();
	for (int i = 1; i <= n; ++i)
		ss[i] = (ss[i - 1] + (s[i - 1] == 'B') + 1) % 3;
	for (int i = 1; i <= m; ++i)
		tt[i] = (tt[i - 1] + (t[i - 1] == 'B') + 1) % 3;
	while (q--) {
		int a, b, c, d; std::cin >> a >> b >> c >> d, --a, --c;
		std::cout << ((ss[b] - ss[a] - tt[d] + tt[c]) % 3 == 0 ? "YES" : "NO") << '\n';
	}
	return 0;
}