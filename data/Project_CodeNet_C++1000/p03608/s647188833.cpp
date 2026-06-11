#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

static const int MAXN = 200;
ll d[MAXN][MAXN];
int n, m, r;

void floyd() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (d[i][k] == LINF) continue;
            for (int j = 0; j < n; ++j) {
                if (d[k][j] == LINF) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> r;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = ((i == j) ? 0 : LINF);
        }
    }

    vector<int> R(r);
    rep(i, r) {
        int t;
        cin >> t;
        --t;
        R[i] = t;
    }

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        d[a][b] = c;
        d[b][a] = c;
    }

    floyd();

    ll ans = LINF;
    sort(R.begin(), R.end());
    do {
        ll sum = 0;
        for (int i = 1; i < r; ++i) {
            sum += d[R[i-1]][R[i]];
        }
        chmin(ans, sum);
    } while(next_permutation(R.begin(), R.end()));

    cout << ans << endl;

    return 0;
}