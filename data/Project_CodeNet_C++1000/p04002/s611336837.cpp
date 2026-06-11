#include<bits/stdc++.h>

#define LL long long
#define RG register

using namespace std;
template<class T> inline void read(T &x) {
	x = 0; RG char c = getchar(); bool f = 0;
	while (c != '-' && (c < '0' || c > '9')) c = getchar(); if (c == '-') c = getchar(), f = 1;
	while (c >= '0' && c <= '9') x = x*10+c-48, c = getchar();
	x = f ? -x : x;
	return ;
}
template<class T> inline void write(T x) {
	if (!x) {putchar(48);return ;}
	if (x < 0) x = -x, putchar('-');
	int len = -1, z[20]; while (x > 0) z[++len] = x%10, x /= 10;
	for (RG int i = len; i >= 0; i--) putchar(z[i]+48);return ;
}
map<pair<int, int>, int> f;
int fx[] = {0, 1, -1, 0, 0, 1, -1, 1, -1};
int fy[] = {0, 0, 0, 1, -1, -1, 1, 1, -1};
int ans[10], H, W, n;
int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	read(H), read(W), read(n);
	for (int i = 1, x, y; i <= n; i++) {
		read(x), read(y);
		for (int j = 0; j <= 8; j++)
			if (x + fx[j] > 1 && y + fy[j] > 1 && x + fx[j] < H && y + fy[j] < W)
				f[make_pair(x + fx[j], y + fy[j])]++;
	}
	printf("%lld\n", 1ll * (H - 2) * (W - 2) - f.size());
	for (auto i : f) {
		ans[i.second]++;
	}
	for (int i = 1; i <= 9; i++) printf("%d\n", ans[i]);
	return 0;
}
