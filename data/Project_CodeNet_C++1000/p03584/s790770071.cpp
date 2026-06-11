#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
const int MX = 100005;
int n, k, a[MX], b[MX];
ll ans;
int main(){
	scanf("%d%d", &n, &k);
	rep(i,n){
		scanf("%d%d", a+i, b+i);
		if((k|a[i])==k) ans += b[i];
	}
	rep(i,30) if(k>>i&1){
		int t = (k>>i<<i)-1;
		ll tmp = 0;
		rep(j,n) if((t|a[j])==t) tmp += b[j];
		ans = max(ans, tmp);
	}
	printf("%lld\n", ans);
}