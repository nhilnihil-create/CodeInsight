#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	ll a, b;
	cin >> a >> b;
	rep(i, n-1){
		ll ia, ib;
		cin >> ia >> ib;
		ll as = 0;
		if(a%ia == 0){
			as = a/ia;
		}else{
			as = a/ia + 1;
		}
		ll na0 = ia*as;
		ll nb0 = ib*as;
		if(na0 < a || nb0 < b){
			na0 = 1000000000000000001;
			nb0 = 1000000000000000001;
		}
		ll bs = 0;
		if(b%ib == 0){
			bs = b/ib;
		}else{
			bs = b/ib + 1;
		}
		ll na1 = ia*bs;
		ll nb1 = ib*bs;
		if(na1 < a || nb1 < b){
			na1 = 1000000000000000001;
			nb1 = 1000000000000000001;
		}
		if(na0+nb0 < na1+nb1){
			a = na0;
			b = nb0;
		}else{
			a = na1;
			b = nb1;
		}
	}
	ll ans = a + b;
	cout << ans << endl;
	return 0;
}