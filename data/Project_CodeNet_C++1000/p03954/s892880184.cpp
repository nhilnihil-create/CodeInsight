#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read() {
	int ans = 0, flag = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') flag = - flag; ch = getchar();}
	while(ch >= '0' && ch <= '9') {ans = ans * 10 + ch - '0'; ch = getchar();}
	return ans * flag;
}
const int N = 100010;
#define mid ((l + r) >> 1)
int n, a[N << 1];
bool vis[N << 1];
bool p[N << 1];
bool check(int x) {
	memset(p, 0, sizeof(p));
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i < 2 * n; ++ i) {
		if(a[i] < x) vis[i] = 0;
		else vis[i] = 1;
		if(i - 1 && vis[i] == vis[i - 1])
			p[i - 1] = p[i] = 1;
	}
	int dis = n, col = 0;
	if(p[n]) return vis[n];
	else {
		for(int i = n - 1; i; -- i)
			if(p[i]) {
				dis = n - i;
				col = vis[i];
				break;
			}
		for(int i = n + 1; i < 2 * n; ++ i) {
			if(p[i]) {
				if(i - n < dis) {
					dis = i - n;
					col = vis[i];
				}
				break;
			}
		}
		if(dis == n) return vis[n] ^ ((n - 1) % 2);
		else return col;
	}
}
int main() {
	n = read();
	for(int i = 1; i < 2 * n; ++ i)
		a[i] = read();
	int l = 1, r = n * 2 - 1, ans;
	while(l <= r) {
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}