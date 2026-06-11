#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {0,1,0,-1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << endl;
}
const int mod = 1e9 + 7;
//const int mod = 998244353;

int main(){
	ll n,k; cin >> n >> k;
	vector<int> a(n); rep(i,n) cin >> a[i];
	rep(i,n) if(a[i] >= k) a[i] = 0;
	sort(rall(a));
	while(!a.empty() && a.back() == 0) a.pop_back(), n--;
	vector<vector<int>> dp(n+1,vector<int>(k+1,0));
	dp[0][0] = 1;
	rep(i,n){
		rep(j,k+1){
			dp[i+1][j] = dp[i][j];
			if(j-a[i] >= 0) dp[i+1][j] += dp[i][j-a[i]];
		}
	}
	vector<vector<int>> ep(n+1,vector<int>(k+1,0));
	rep(j,k+1) ep[n][j] = 1;
	rep(i,n+1) ep[i][0] = 1;
	ll ans = 0;
	for(ll i=n-1; i>=0; i--){
		bool flag = true;
		rep(j,k-a[i]){
			if(dp[i][j] && ep[i+1][k-j-1] - ep[i+1][k-a[i]-1-j]){
				flag = false;
				break;
			}
		}
		REP(j,k-a[i],k) if(dp[i][j]) flag = false;
		if(flag) ans++;
		rep(j,k){
			ep[i][j+1] = ep[i][j] + ep[i+1][j+1] - ep[i+1][j];
			if(j+1-a[i]==0) ep[i][j+1]++;
			else if(j+1-a[i]>0) ep[i][j+1] += ep[i+1][j+1-a[i]]-ep[i+1][j-a[i]];
		}
	}
	cout << ans << endl;
}
