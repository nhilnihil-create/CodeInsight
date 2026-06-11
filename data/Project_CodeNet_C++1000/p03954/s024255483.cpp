#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
#include <unordered_map>
#include <fstream>
#include <time.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef pair<int,int> pii;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(int i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 5020000;
ll dy[8] = {1,-1,0,0,1,-1,1,-1};
ll dx[8] = {0,0,1,-1,1,-1,-1,1};
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
ll pcount(ll x) {return __builtin_popcountll(x);}
const int mod = 1e9 + 7;
//const int mod = 998244353;

int main(){
	int n; cin >> n;
	int N = 2*n-1;
	vl a(N); rep(i,N) cin >> a[i];
	int ok = N, ng = 0;
	while(ok-ng > 1){
		int mid = (ng+ok) / 2;
		vb v(N);
		int s = 0;
		rep(i,N) v[i] = (a[i] <= mid), s += v[i];
		int last = -1;
		int mn = n;
		REP(i,n-1,N){
			if(v[i] == v[i+1]){
				mn = i-n+1; last = v[i];
				break;
			}
		}
		for(int i=n-1; i>=1; i--){
			if(v[i] == v[i-1]){
				if(mn == n-1-i){
					if(last != v[i]){
						last = v[n-1] ^ (mn & 1 ^ 1);
					}
				}
				if(chmin(mn, n-1-i)){
					last = v[i];
				}
				break;
			}
		}
		if(mn == n) last = v[n-1] ^ (n & 1 ^ 1);
		if(last == 1) ok = mid;
		else ng = mid;
	}
	cout << ok << "\n";
}