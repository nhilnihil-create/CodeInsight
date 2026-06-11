#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


const ll limit = 100010;
struct edge{
    ll to;
    ll cost;
};

vector<edge> tree[limit];
ll depth[limit];


void dfs(ll v,ll p,ll d){
    depth[v] = d;
    for(auto &e : tree[v]){
        if(e.to == p) continue;
        dfs(e.to,v,d+e.cost);
    }
}


int main(){
    FIN;
    ll n; cin >> n;
    //vector<vector<ll>> c(n,vector<ll>(n,0));
    //Graph G(n);
    for(ll i=0;i<n-1;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }

    ll q,k;
    cin >> q >> k;
    k--;

    dfs(k,-1,0);

    for(ll i=0;i<q;i++){
        ll x,y;
        cin >> x >> y;
        x--; y--;
        cout << depth[x] + depth[y] << endl;
    }

    return 0;
}
