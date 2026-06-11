#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e18;

int main() {
    ll N, M;
    cin >> N >> M; //頂点数と辺数の入力
    const ll NMAX = 1000;
    const ll MMAX = 2000;
    ll a[MMAX], b[MMAX];
    ll c[MMAX];
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i] >> c[i]; //辺およびその重みの入力
        c[i] = -c[i];
    }
    ll dist[NMAX];
    for (int i = 0; i < N; ++i) {
        dist[i] = INF;
    }
    dist[0] = 0;
    for (int loop = 0; loop < N - 1; ++ loop) {
        for (int i = 0; i < M; ++i) {
            if (dist[a[i] - 1] == INF) continue;
            if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
            }
        }
    }
    ll ans = dist[N - 1];
    bool negative[NMAX];
    for (int i = 0; i < N; ++i) {
        negative[i] = false;
    }
    for (int loop = 0; loop < N ; ++ loop) {
        for (int i = 0; i < M; ++i) {
            if (dist[a[i] - 1] == INF) continue;
            if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                negative[b[i] - 1] = true;
            }
            if (negative[a[i] - 1] == true) {
                negative[b[i] - 1] = true;
            }
        }
    }
    if (negative[N - 1]) cout << "inf" << endl;
    else cout << -ans << endl;
    return 0;
}
