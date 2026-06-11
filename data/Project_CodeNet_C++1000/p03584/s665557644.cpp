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
#include <cassert>
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
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
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

ll n,K;
vl a(101010),b(101010);

ll rec(ll k, ll plus, ll p){
	ll res = 0;
	if(p == -1){
		rep(i,n) if((a[i] - (a[i] & plus)) == 0) res += b[i];
		return res;
	}
	ll np = p;
	rep(i,n){
		if((a[i] - (a[i] & plus)) < 1<<p) res += b[i]; 
	}
	k -= 1<<p;
	plus += 1<<p;
	while((1<<np) > k) np--;
	return max(res,rec(k,plus,np));
}


int main(){
	cin >> n >> K;
	rep(i,n) cin >> a[i] >> b[i];
	ll p = -1;
	while((1<<(p+1)) <= K) p++;
	cout << rec(K,0,p) << endl;
}