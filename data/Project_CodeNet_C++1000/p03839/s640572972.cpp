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
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {0,1,0,-1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << endl;
}
#define INT_MAX 1<<30
const int mod = 1e9+7;

int main(){
	ll n,k; cin >> n >> k;
	vl a(n); rep(i,n) cin >> a[i];
	vl sum(n-k+1,0);
	rep(i,n-k){
		sum[i+1] += sum[i] + max(0LL,a[i]);
	}
	ll s = 0;
	REP(i,n-k,n) s += a[i];
	ll ans = max(0LL,s) + sum[n-k];
	//print2(s,sum[n-k]);
	ll add = 0;
	for(ll i=n-k-1; i>=0; i--){
		s += a[i];
		s -= a[i+k];
		add += max(a[i+k],0LL);
		chmax(ans, max(0LL,s) + sum[i] + add);
		//print3(s,sum[i],add);
	}
	cout << ans << endl;
}