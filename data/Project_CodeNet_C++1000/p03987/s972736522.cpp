#include<bits/stdc++.h>
#define Rint register int
using namespace std;
typedef long long LL;
const int N = 200003;
int n, a[N], st[18][N], lg2[N];
LL ans;
inline int calc(int l, int r){
	int k = lg2[r - l + 1];
	return a[st[k][l]] < a[st[k][r - (1 << k) + 1]] ? st[k][l] : st[k][r - (1 << k) + 1];
}
inline void solve(int l, int r){
	if(l == r) ans += a[l];
	if(l >= r) return;
	int mid = calc(l, r);
	ans += (LL) a[mid] * (mid - l + 1) * (r - mid + 1);
	solve(l, mid - 1); solve(mid + 1, r);
}
int main(){
	scanf("%d", &n);
	for(Rint i = 1;i <= n;i ++) scanf("%d", a + i), st[0][i] = i;
	for(Rint i = 1;i <= 18;i ++)
		for(Rint j = 1;j <= n - (1 << i) + 1;j ++)
			st[i][j] = a[st[i - 1][j]] < a[st[i - 1][j + (1 << i - 1)]] ? st[i - 1][j] : st[i - 1][j + (1 << i - 1)];
	lg2[0] = -1;
	for(Rint i = 1;i <= n;i ++) lg2[i] = lg2[i >> 1] + 1;
	solve(1, n);
	printf("%lld", ans);
}