#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;
#define REP(i,b,e) for(ll i=b; i<e; i++)
#define fi first
#define se second

int main(){
	int n;
	scanf("%d", &n);
	P a[n+1];
	REP(i, 0, n){
		a[i].se = i+1;
		scanf("%ld", &a[i].fi);
	}
	a[n] = P(0, 0);
	std::sort(a, a+n, std::greater<P>());

	ll ans[n+1] = {}, x = a[0].se, sum = 0;
	REP(j, 0, n+1){
		sum += a[j].fi;
		if(a[j].se<x){
			ans[x] = sum - a[j].fi * (j+1);
			sum = a[j].fi * (j+1);
			x = a[j].se;
			continue;
		}
	}

	REP(i, 0, n) printf("%ld\n", ans[i+1]);
	return 0;
}

