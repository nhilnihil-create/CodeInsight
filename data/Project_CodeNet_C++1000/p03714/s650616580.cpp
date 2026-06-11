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
const int MAX = 510000;
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
const int mod = 1e9 + 7;
//const int mod = 998244353;

int main(){
    int n; cin >> n;
    ll N = 3*n;
    vl a(N); rep(i,N) cin >> a[i];
    ll sl = 0, sr = 0;
    multiset<ll> l,m,r;
    rep(i,n){
        l.insert(a[i]);
        sl += a[i];
    }
    REP(i,n,N){
        r.insert(a[i]);
    }
    rep(i,n){
        auto itr = r.begin();
        sr += *itr;
        m.insert(*itr);
        r.erase(itr);
    }
    ll ans = sl - sr;
    REP(i,n,2*n){
        auto itr = l.begin();
        if(*itr < a[i]){
            sl -= *itr;
            l.erase(itr);
            l.insert(a[i]);
            sl += a[i];
        }
        if(m.find(a[i]) != m.end()){
            sr -= a[i];
            m.erase(m.find(a[i]));
            auto itr2 = r.begin();
            m.insert(*itr2);
            sr += *itr2;
            r.erase(itr2);
        }else{
            r.erase(r.find(a[i]));
        }
        chmax(ans, sl - sr);
    }
    cout << ans << "\n";
}