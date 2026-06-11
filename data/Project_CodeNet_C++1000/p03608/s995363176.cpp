#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e9 + 7;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll N, M, R;
    cin >> N >> M >> R;
    vector<ll> r(R);
    rep1(i, R){
        cin >> r[i];
        r[i]--;
    }
    vector<vector<ll> > d(201, vector<ll>(201, INF));
    rep1(i, M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    for (ll k = 0; k < N; k++){       // 経由する頂点
        for (ll i = 0; i < N; i++) {    // 始点
            for (ll j = 0; j < N; j++) {  // 終点
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    ll ans = INF;
    sort(r.begin(), r.end());
    ll P[R];
    rep1(i, R) P[i] = r[i];
    do {
        ll res = 0;
        rep1(i, R-1) res += d[P[i+1]][P[i]];
        ans = min(ans, res);
    } while(next_permutation(P, P+R));
    cout << ans << endl;
    //printf("%.12f", ans);
}