#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P>IP;
typedef vector<ll> V;
typedef vector<V> V2;
typedef vector<vector<P> > G;
void g_dir(G &graph, ll a, ll b, ll w = 1){graph[a].push_back(P(b, w));}
void g_undir(G &graph, ll a, ll b, ll w = 1){g_dir(graph, a, b, w);g_dir(graph, b, a, w);}
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}
const ll INF = 1145141919;
const ll MOD = 1000000007;
const ll NUM = 101010;

void ruiseki_inc(V &v, vector<P>&p){
    rep(i, v.size())v[i] = 0;
    rep(i, p.size()){
        v[p[i].first]++;
        v[p[i].second + 1]--;
    }
    rep(i, v.size() - 1)v[i + 1] += v[i];
    rep(i, p.size()){
        v[p[i].second + 1]-=p[i].second - p[i].first + 1;
    }
    rep(i, v.size() - 1)v[i + 1] += v[i];
}

int main(){

    ll N, M;
    cin >> N >> M;
    V a(N);
    rep(i, N)cin >> a[i];
    ll sum = 0;
    V v(2 * M + 10, 0);
    vector<P>p;
    rep(i, N - 1){
        ll x = a[i], y = a[i + 1];
        if(x > y)y += M;
        sum += y - x;
        p.push_back(P(x + 2, y));                
    }
    ruiseki_inc(v, p);
    ll ans = sum;
    rep1(i, M)chmin(ans, sum - v[i] - v[i + M]);
    cout << ans << endl;

    return 0;
}