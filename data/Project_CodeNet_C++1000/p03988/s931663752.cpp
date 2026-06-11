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

int main(){
    ll n; cin >> n;
    ll mx = 0;
    vl a(n); rep(i,n) cin >> a[i], chmax(mx,a[i]);
    ll h = (mx+1)/2;
    sort(rall(a));
    vl cnt(mx+1,0);
    rep(i,n){
        if(a[i]<h){
            puts("Impossible");
            return 0;
        }
        cnt[a[i]]++;
    }
    for(ll i=h+1; i<=mx; i++){
        if(cnt[i] < 2){
            puts("Impossible");
            return 0;
        }
    }
    if(mx&1){
        if(cnt[h] == 2) puts("Possible");
        else puts("Impossible");
    }else{
        if(cnt[h] == 1) puts("Possible");
        else puts("Impossible");
    }
}