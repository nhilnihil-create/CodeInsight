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
template<class T> T ika_max(set<T> &S, const T &x){
    typename set<T>::iterator it = S.lower_bound(x);
    if(it == S.end())it--;
    else if(*it > x)it--;
    return *it;
}
template<class T> T ijo_min(set<T> &S, const T &x){
    return *S.lower_bound(x);
}
int main(){

    ll N;
    cin >> N;
    vector<P>v;
    rep1(i, N){
        ll x;
        cin >> x;
        v.push_back(P(x, i));
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    set<ll>S;
    S.insert(0);
    S.insert(N + 1);
    rep(i, N){
        ll x = v[i].first;
        ll idx = v[i].second;
        ans += x * (idx - ika_max(S, idx)) * (ijo_min(S, idx) - idx);
        S.insert(idx);
    }
    cout << ans << endl;
    
    return 0;
}