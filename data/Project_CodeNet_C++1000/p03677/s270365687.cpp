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

ll cnt[202020];

int main(){

    ll N, M;
    cin >> N >> M;
    V v(N);
    rep(i, N)cin >> v[i];
    ll sum = 0;
    rep(i, N - 1){
        ll a = v[i], b = v[i + 1];
        if(a > b)b += M;
        cnt[a + 2]++;
        cnt[b + 1]--;
        sum += b - a;
    }
    rep1(i, 202000)cnt[i] += cnt[i - 1];
    rep(i, N - 1){
        ll a = v[i], b = v[i + 1];
        if(a > b)b += M;
        cnt[b + 1] -= b - a - 1;
    }
    rep1(i, 202000)cnt[i] += cnt[i - 1];
    // cout << sum << endl;
    // rep1(i, 2 * M)cout << i << " : " << cnt[i] << endl;
    ll ans = sum;
    rep1(i, M)chmin(ans, sum - cnt[i] - cnt[i + M]);
    cout << ans << endl;

    return 0;
}