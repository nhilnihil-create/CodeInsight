#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

struct edge{
    int from, to;
    ll cost;
};

int main(){
    int N, M;
    cin >> N >> M;
    edge es[M];
    rep(i, M){
        cin >> es[i].from >> es[i].to >> es[i].cost;
        es[i].from--, es[i].to--;
    }
    ll d[N];
    fill(d, d+N, -INF);
    d[0] = 0;
    rep(i, N){
        rep(j, M){
            edge e = es[j];
            if(d[e.from] != -INF && d[e.to] < d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
            }
        }
    }
    ll ans = d[N-1];
    rep(i, N){
        rep(j, M){
            edge e = es[j];
            if(d[e.from] != -INF && d[e.to] < d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
            }
        }
    }
    if(ans == d[N-1]) cout << ans << endl;
    else cout << "inf" << endl;
}