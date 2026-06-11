#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
int a[N], f[N][32];
int n, m, L, cnt = 2;

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&L);
	for (int i=1;i<=n;i++) {
		while (a[cnt] - a[i] <= L&& cnt <= n) cnt ++;
		f[i][0] = cnt - 1;
	}
	for (int i=1;i<=30;i++) {
		for (int j=1;j<=n;j++)
			f[j][i] = f[f[j][i-1]][i-1];
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++) {
		int x, y;
		scanf("%d%d",&x,&y);
		if (x > y) swap(x, y);
		int ans = 0;
		for (int j=30;j>=0;j--) {
			if (f[x][j] >= y) continue;
			ans += 1 << j, x = f[x][j];
		}
		printf("%d\n",ans+1);
	}
	return 0;
}