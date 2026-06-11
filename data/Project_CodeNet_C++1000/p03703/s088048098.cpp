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

template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};


int main(){
	ll n,k; cin >> n >> k;
	vl a(n); rep(i,n) cin >> a[i], a[i] -= k;
	REP(i,1,n) a[i] += a[i-1];
	vpl b(n);
	rep(i,n) b[i].first = a[i], b[i].second = i;
	sort(all(b));
	ll now = -inf;
	ll id = 0;
	ll num = n+1;
	rep(i,n){
		if(now == b[i].first) a[b[i].second] = id;
		else{
			id++;
			if(b[i].first >= 0) chmin(num,id);
			now = b[i].first;
			a[b[i].second] = id;
		}
	}
	BinaryIndexedTree<ll> bit(n+1);
	rep(i,n){
		bit.add(a[i],1);
	}
	ll ans = 0;
	rep(i,n){
		ans += n-i - bit.sum(num-1);
		num = a[i];
		bit.add(a[i],-1);
	}
	cout << ans << endl;
}