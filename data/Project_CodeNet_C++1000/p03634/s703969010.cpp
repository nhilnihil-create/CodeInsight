#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<pair<ll,ll> > to[100005];
vector<ll> dp(100005);
// Kからの最短距離を各頂点について求めて、最後に足し算すれば良い。

void dfs(ll v, ll parent, ll distance){
    dp.at(v) = distance;
    for(pair<ll, ll> child: to[v]){
        if(child.first == parent) continue;
        dfs(child.first, v, distance + child.second);
    }
}

int main(){
    ll N, Q, K;
    cin >> N;
    rep(i, N-1) {
        ll A, B, C;
        cin >> A >> B >> C;
        A--;
        B--;
        to[A].emplace_back(make_pair(B, C));
        to[B].emplace_back(make_pair(A, C));
    }
    cin >> Q >> K;
    dfs(K-1, -1,0);
    rep(i, Q) {
        ll x, y;
        cin >> x >> y;
        cout << dp.at(x-1) + dp.at(y-1) << endl;
    }
}