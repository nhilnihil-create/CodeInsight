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
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << "\n";}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << "\n";
}
const int mod = 1e9 + 7;
//const int mod = 998244353;

int main(){
	ll n,m; cin >> n >> m;
	vl a(n); rep(i,n) cin >> a[i], a[i]--;
	vl b(2*m+1,0);
	vl c(2*m+1,0);
	ll cnt = 0;
	rep(i,n-1){
		ll cur = (a[i] > a[i+1]) ? a[i+1]+m : a[i+1];
		cnt += cur - a[i];
		if(a[i] + 1 == cur) continue;
		ll pre = a[i] + 2;
		b[cur+1] -= cur + 1 - pre;
		c[pre]++; c[cur+1]--;
	}
	rep(i,2*m) c[i+1] += c[i];
	rep(i,2*m+1) b[i] += c[i];
	rep(i,2*m) b[i+1] += b[i];
	/*rep(i,2*m+1) cout << b[i] << " ";
	cout << "\n";*/
	rep(i,m) b[i] += b[i+m];
	cout << cnt - *max_element(all(b)) << endl;
}