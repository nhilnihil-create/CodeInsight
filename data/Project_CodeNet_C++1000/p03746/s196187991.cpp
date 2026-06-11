#include <iostream>
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
const int mod = 1e9 + 7;
const int MAX = 510000;
const int V = 100005;
ll dy[8] = {1,0,-1,0,1,-1,1,-1};
ll dx[8] = {0,1,0,-1,1,-1,-1,1};
const double pi = acos(-1);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}

vvl G(V);
vector<bool> visit(V,false);
vl ans;
bool dfs(ll u){
    visit[u] = true;
    for(auto v : G[u]){
        if(visit[v]) continue;
        visit[v] = true;
        ans.push_back(v);
        bool b = dfs(v);
        if(b) return true;
    }
    return true;
}

int main(){
    ll n,m; cin >> n >> m;
    rep(i,m){
        ll a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ans.push_back(0);
    dfs(0);
    rep(i,n) visit[i] = false;
    for(auto i : ans) visit[i] = true;
    reverse(all(ans));
    dfs(0);
    cout << ans.size() << endl;
    for(auto i : ans) cout << i+1 << " ";
}
