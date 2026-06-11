#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int N, M, R;
    cin >> N >> M >> R;
    vector<int> r(R);
    rep(i, R) {
        cin >> r[i];
        r[i]--;
    }
    sort(all(r));

    vector<vector<ll>> d(N, vector<ll>(N, INF));
    rep(i, N) d[i][i] = 0;
    rep(i, M) {
        int A, B, C;
        cin >> A >> B >> C;
        A--; B--;
        d[A][B] = C;
        d[B][A] = C;
    }

    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                chmin(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    ll ans = INF;

    do {
        ll res = 0;
        rep(i, R - 1) {
            res += d[r[i]][r[i + 1]];
        }
        chmin(ans, res);
    } while (next_permutation(all(r)));

    cout << ans << endl;
    return 0;
}