#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100005;
int n, x[MAXN], op[MAXN];
LL ans, rs[MAXN], suf[MAXN];
int main () {
	scanf("%d", &n);
	char ch[2]; op[1] = 1;
	for(int i = 1; i < n; ++i) {
		scanf("%d%s", &x[i], ch); op[i+1] = ch[0]=='+'?1:-1;
		ans += x[i]*op[i];
	}
	scanf("%d", &x[n]); ans += x[n]*op[n];
	for(int i = n; i >= 1; --i)
		rs[i] = (op[i+1] == 1 ? rs[i+1] : 0) + x[i],
		suf[i] = suf[i+1] + x[i];
	LL pre = 0;
	for(int i = 1; i <= n; pre += x[i]*op[i], ++i)
		if(op[i] == -1 ) {
			ans = max(ans, pre + suf[i] - 2*rs[i]);
		}
	printf("%lld\n", ans);
}
