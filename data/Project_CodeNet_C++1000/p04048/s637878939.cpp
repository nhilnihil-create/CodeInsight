#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, px;
ll ans;

int main(){
	scanf("%lld %lld", &n, &px);
	ll a, b;
	a = min(px, n - px); b = max(px, n - px);
	while(a){
		if(b % a != 0){
			ans += (b / a) * 2 * a;
			b = b % a; swap(a, b);
		}else{
			ans += (b / a) * 2 * a;
			ans -= a;
			break;
		}
	}
	printf("%lld\n", ans + n);
	return 0;
}