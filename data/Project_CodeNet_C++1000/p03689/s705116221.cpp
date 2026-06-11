#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 505;
int ans[MAXN][MAXN], tmp[MAXN][MAXN], h, H, w, W, rev;

int main() {
	scanf("%d%d%d%d", &H, &W, &h, &w);
	if (H % h == 0 && W % w == 0) return puts("No"), 0;
	puts("Yes");
	if (W % w == 0) swap(H, W), swap(h, w), rev = true;
	int t = W / w, x = t + 1;
	for (int i = h; i <= H; i += h)
	for (int j = 1; j <= W; j++)
		ans[i][j] = j % w == 0 ? (1 - w) * x - 1 : x;
	if (rev) {
		memcpy(tmp, ans, sizeof(tmp));
		for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++) ans[j][i] = tmp[i][j];
		swap(H, W), swap(h, w);
	}
	for (int i = 1; i <= H; i++, puts(""))
	for (int j = 1; j <= W; j++) printf("%d ", ans[i][j]);
	return 0;
}