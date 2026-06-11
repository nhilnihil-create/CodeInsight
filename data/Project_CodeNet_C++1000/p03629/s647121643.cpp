#include <cstdio>
#include <cstring>
int n, nxt[26][200005], pre[26][200005], now, cnt[26], l[200005], r[200005], idx;
char buf[200005];
int main() {
	std::scanf("%s", buf + 1);
	n = std::strlen(buf + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 26; j++) pre[j][i] = pre[j][i - 1];
		++pre[buf[i] - 97][i];
	}
	r[idx = 1] = n;
	for (int i = n; i; i--) {
		for (int j = 0; j < 26; j++) nxt[j][i] = nxt[j][i + 1];
		nxt[buf[i] - 97][i] = i;
		now += cnt[buf[i] - 97]++ == 0;
		if (now == 26) {
			now = 0;
			for (int j = 0; j < 26; j++) cnt[j] = 0;
			l[idx] = i;
			r[++idx] = i - 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) if (!pre[i][r[idx]]) {
		std::putchar((ans = i) + 97); 
		break; 
	}
	for (int i = idx - 1; i; i--) {
		int x = nxt[ans][l[i]];
		for (int j = 0; j < 26; j++) if (!(pre[j][r[i]] - pre[j][x])) {
			std::putchar((ans = j) + 97); break; 
		}
	}
	return 0;
}