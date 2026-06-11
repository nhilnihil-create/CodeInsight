#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976
const double PI = 3.1415926535897932;


const int MAX_N = 10010;
ll g[MAX_N][MAX_N];   //g[i][j] はすべてinfで初期化
ll d[MAX_N];
bool used[MAX_N];
int n;

void dijkstra(int s){
    fill(d,d+n,inf);
    fill(used,used+n,false);
    d[s] = 0;

    while(true){
        int v = -1;
        for(int u = 0; u < n; u++){
            if(!used[u] && (v == -1 || d[u] < d[v])){
                // 1番最小のd[u]となるuを、v = u　として保存
                // ループを抜けた後に、vを介して[u]を更新
                v = u;
            }
        }
        //　この時点でd[u]が最小となるuは決定されている。
        if(v == -1) break;
        used[v] = true;
        for(int u = 0; u < n; u++){
            d[u] = min(d[u],d[v] + g[v][u]);
        }
    }
}

int main()
{
    ll m; cin >> n >> m;
    rep(i,n) rep(j,n) g[i][j] = inf;
    vector<P> v;
    rep(i,m){
        ll a,b,c; cin >> a >> b >> c;
        a--; b--;
        g[a][b] = c;
        g[b][a] = c;
        v.push_back(make_pair(a,b));
    }
    ll ans = 0;
    rep(i,m){
        P p = v[i];
        ll a = p.first, b = p.second;
        ll cost = g[a][b];

        dijkstra(a);
        ll tmp = d[b];
        if(cost > tmp) ans++;
    }
    cout << ans << endl;
}