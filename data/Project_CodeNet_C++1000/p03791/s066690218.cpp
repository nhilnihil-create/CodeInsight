#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	ll n;
	cin >> n;	
	ll x[n];
	zep(i, 0, n){
		cin >> x[i];
	}
	
	ll ans = 1;
	ll goal = 0;
	zep(i, 0, n){
		if(x[i] < 2*(i-goal)+1){
			//print(x[i])
			ans *= i+1-goal;
			ans %= MOD;
			goal++;
		}
	}
	//print(4311014400%MOD)
	//print(goal)
	while(goal != n){
		ans *= n-goal;
		ans %= MOD;
		goal++;
	}
	
	print(ans)
	return 0;
}