#include<bits/stdc++.h>
using namespace std ; 
# define pb push_back
# define ll long long
# define mp make_pair 
# define endl "\n"
# define vi vector<int>
# define vc vector<char>
# define vll vector<ll> 
# define pi pair<int,int> 
const int MOD = 1e9 + 7 ; 
const ll inf = 1e18 ; 

void solve() {
	ll n , m ; 
	cin >> n >> m ; 
	if(abs(n-m) > 1) {
		cout << 0 ; 
		return ; 
	}
	 
	ll ans = 1 ; 
	for(ll i = 1 ; i <= n ; ++i) {
		ans = ans * i ; 
		ans = ans%MOD ;  
	}
	for(ll i = 1 ; i <= m ; ++i) {
		ans = ans * i ; 
		ans = ans%MOD ;  
	}
	if(n == m)  {
		ans *= 2 ;
		ans = ans%MOD ; 
	}
	cout << ans ; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ; 
	int t ; 
	//cin >> t ; 
	t = 1 ;
	while(t--)
		solve() ; 
	return 0; 
}
