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
#include <complex>
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
ll dy[8] = {0,-1,0,1,1,-1,1,-1};
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
const ll mod = 1e9 + 7;
//const int mod = 998244353;

vvl G(101010);
vl a(101010);
vl d(101010,0);

ll dfs(ll u, ll p){
    if(d[u] == 1) return a[u];
    ll sum = 0;
    ll mx = 0;
    for(auto v : G[u]){
        if(v == p) continue;
        ll df = dfs(v,u);
        if(df == -1) return -1;
        chmax(mx, df);
        sum += df;
    }
    ll t;
    if(sum - mx < mx) t = sum - mx;
    else t = sum / 2;
    ll rest = sum - t * 2;
    if(a[u] > sum || a[u] < t + rest) return -1;
    return a[u] - (sum - a[u]);
}

int main(){
    ll n; cin >> n;
    rep(i,n) cin >> a[i];
    rep(i,n-1){
        ll u,v; cin >> u >> v; u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
        d[u]++; d[v]++;
    }
    if(n == 2){
        if(a[0] == a[1]) puts("YES");
        else puts("NO");
        return 0;
    }
    ll s = 0;
    rep(i,n) if(d[i] >= 2){
        s = i;
        break;
    }
    if(dfs(s,-1) == 0) puts("YES");
    else puts("NO");
}