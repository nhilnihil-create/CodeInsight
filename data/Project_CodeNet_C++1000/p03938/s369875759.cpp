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

int main(){

    ll N;
    cin >> N;
    V a(N + 2, 0), b(N + 2, 0);
    rep1(i, N)a[i] = 1;
    rep1(i, N)b[i] = 1;
    rep1(i, N){
        ll x;
        cin >> x;
        a[x] += i;
        b[x] += i;     
    }
    rep1(i, N)a[i] += a[i - 1];
    rrep1(i, N)b[i] += b[i + 1];
    rep1(i, N){
        cout << a[i] - a[1] + 1;
        if(i == N)cout << endl;
        else cout << " ";
    }
    rep1(i, N){
        cout << b[i] - b[N] + 1;
        if(i == N)cout << endl;
        else cout << " ";
    }
    
    return 0;
}