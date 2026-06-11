#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <ctime>
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
template<typename T> inline void print(T &a){
    rep(i,a.size()) cout << a[i] << " ";
    cout << "\n";
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << "\n";}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << "\n";
}
const int mod = 1e9 + 7;
//const int mod = 998244353;

ll n,k;
vl a(101010), b(101010);

ll rec(ll x){
	ll res = 0;
	if(x == 0){
		rep(i,n){
			if(a[i] == 0) res += b[i];
		}
		return res;
	}
	ll p = 0;
	while(1<<p <= x) p++;
	p--;
	rep(i,n){
		if(a[i] > x) continue;
		else if(a[i]>>p & 1) a[i] -= 1<<p;
		else res += b[i];
	}
	chmax(res, rec(x - (1<<p)));
	return res;
}

int main(){
	cin >> n >> k;
	rep(i,n) cin >> a[i] >> b[i];
	cout << rec(k) << endl;
}
