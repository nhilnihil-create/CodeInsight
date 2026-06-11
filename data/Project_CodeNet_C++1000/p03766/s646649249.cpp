#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
const ll Mod = 1e9 + 7;
const ll Inf = 2242545357980376863LL;
const ll Log = 20;
const ll N = 1ll << Log;
const int Maxn = 1e6 + 10;
const int Base = 101;

ll dp[Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n;
	cin >> n;
	
	ll s = 0;
	dp[0] = 1;
	dp[1] = 1;
	s = 2;
	ll cnt, ans = 0;
	for(int i = 0; i <= n; i++){
		if(i >= 2){
			dp[i] = s - dp[i - 2];
			s = (s + dp[i]) % Mod;
		}
		if(i == n){
			ans += dp[i];		
		}
		if(i == n - 1){
			ans += dp[i] * (n - 1);
		}
		if(i < n - 1){
			cnt = (n-1) * (n - 1) + (i + 1);
			cnt %= Mod;
			//cerr << "!" <<  << '\n';
			ans += dp[i] * cnt;
		}
		ans %= Mod;
		//cout << ans << '\n';
	}
	cout << (ans + Mod) % Mod;
	
	
	return 0;
}
