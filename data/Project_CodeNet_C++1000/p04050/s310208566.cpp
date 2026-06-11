#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 110;
int n,m,a[M],b[N],cnt,tot,res[N];
int rec[3];
int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m; ++ i) {
		scanf("%d",&a[i]);
		cnt += a[i]&1;
		if (a[i]&1 && cnt <= 2) rec[cnt] = a[i];
	}
	if (cnt > 2) return 0*puts("Impossible");
	if (cnt) res[++tot] = rec[1];
	for (int i = 1;i <= m; ++ i) if (a[i]%2==0) res[++tot] = a[i];
	if (cnt > 1) res[++tot] = rec[2];
	tot = 0;
	if (res[1] != 1) b[++tot] = res[1] - 1;
	for (int i = 2;i < m; ++ i) {
		b[++tot] = res[i];
	}
	if (m == 1) b[++tot] = 1;
	else b[++tot] = res[m] + 1;
	for (int i = 1;i <= m; ++ i) printf("%d ",res[i]);
	printf("\n%d\n",tot);
	for (int i = 1;i <= tot; ++ i) printf("%d ",b[i]);
	puts("");
	return 0;
}