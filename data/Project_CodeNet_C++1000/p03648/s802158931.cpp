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

bool hoge(V &v){
    ll idx = 0;
    rep(i, v.size())if(v[idx] < v[i])idx = i;
    rep(i, v.size())if(i != idx)v[i]++;
    v[idx] -= v.size();
    return v[idx] >= 0;
}

int main(){
    
    ll K;
    cin >> K;
    ll N = 50;
    ll X = (K / N) + N;
    V v(N, X);
    ll Y = N * (X - N + 1);
    for(;Y > K;Y--)hoge(v);
    cout << v.size() << endl;
    rep(i, v.size()){
        cout << v[i];
        if(i + 1 == v.size())cout << endl;
        else cout << " ";
    }
    
    return 0;
}