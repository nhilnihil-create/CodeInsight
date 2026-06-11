#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <string>
using namespace std;

typedef long long int ll;

const ll MOD = 1e9 + 7;

ll fact(ll x){
	ll ans = 1;
	for(ll i=1; i<=x; i++)
		ans = (ans*i)%MOD;
	return ans;
}

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	if(abs(n-m) > 1)
		puts("0");
	else{
		if(n == m){
			ll ans = (fact(n)*fact(m))%MOD;
			cout << (ans<<1)%MOD;
		}
		else{
			ll ans = (fact(n)*fact(m))%MOD;
			cout << ans;
		}
	}
	return 0;
}