#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))


int main(){
    int n;  cin >> n;
    vector<vector<pair<ll, ll>>> g(n);
    
    REP(i, n-1){
        ll a, b, c;     cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(c, b);
        g[b].emplace_back(c, a);
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>,  greater<pair<int, int>>> que;
    vector<ll> path(n, 1e+15);
    int q, k;   cin >> q >> k;
    path[k-1] = 0;
    que.emplace(0, k-1);
    while(!que.empty()){
        pair<ll, ll> p = que.top();   que.pop();
        int v = p.second;
        if(path[v]<p.first) continue;
        for(auto x: g[v]){
            if(path[v] + x.first<path[x.second]){
                path[x.second] = path[v] + x.first;
                que.emplace(path[x.second], x.second);
            }
        } 
    }
    
    REP(i, q){
        int x, y;   cin >> x >> y;
        cout << path[x-1]+path[y-1] << endl;
    }

    
}