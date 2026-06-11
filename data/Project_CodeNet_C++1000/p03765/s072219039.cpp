#include <bits/stdc++.h>

const int MAXN = 100010;
char buf[MAXN];
int pa[MAXN], pb[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> buf; int n = strlen(buf);
	for (int i = 1; i <= n; ++i) pa[i] = pa[i - 1] + (buf[i - 1] == 'B') + 1;
	std::cin >> buf; n = strlen(buf);
	for (int i = 1; i <= n; ++i) pb[i] = pb[i - 1] + (buf[i - 1] == 'B') + 1;
	std::cin >> n;
	while (n --> 0) {
		int l, r, t = 0;
		std::cin >> l >> r; t += pa[r] - pa[l - 1];
		std::cin >> l >> r; t -= pb[r] - pb[l - 1];
		std::cout << (t % 3 == 0 ? "YES" : "NO") << '\n';
	}
	return 0;
}
