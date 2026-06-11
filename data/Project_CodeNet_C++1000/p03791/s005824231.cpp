#include <bits/stdc++.h>
  
using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;

ll memo[100010];

ll f(int n){
	if(memo[n] != -1) return memo[n];
	if(n <= 1) return 1LL;
	return memo[n] = n *f(n-1) % MOD;
}


int main(){
	int n;
	cin>>n;
	vi v(n);
	rep(i,n) cin>>v[i];
	rep(i, 100010) memo[i] = -1;
	memo[0] = 1LL;
	
	int ana = v[0] -1;
	int num = 1;

	ll ans = 1LL;

	for(int i = 1; i < n; i++){
		num++;
		ana += v[i]-v[i-1]-1;
		if(num >=ana+2){
			//(ans *= f(num))%=MOD;
			(ans *= num) %= MOD;
			num--;
			ana++;
		}
	}
	(ans *= f(num))%=MOD;
	cout<<ans<<endl;

}
