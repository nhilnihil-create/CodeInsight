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
	ll i,o,t,j,l,s,z; cin >> i >> o >> t >> j >> l >> s >> z;
	ll ans = o;
	ll ijl = min({i,j,l});
	if((ijl%2==i%2) + (ijl%2==j%2) + (ijl%2==l%2) != 1){
		ans += ijl * 3;
		i -= ijl; j -= ijl; l -= ijl;
		ans += i/2 * 2 + j/2 * 2 + l/2 * 2;
	}else{
		if(ijl == 0) ans += i/2 * 2 + j/2 * 2 + l/2 * 2;
		else{
			if(ijl & 1 ^ 1){
				ijl--; i--; j--; l--;
				ans += 3;
			}
			ans += i/2 * 2 + j/2 * 2 + l/2 * 2;
		}
	}
	cout << ans << endl;
}
