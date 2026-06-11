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

vector<vector<bool>> cnt;
vector<vector<ll>> nextr;

void path(int s, int g) {
    vector<int> path;
    for (int cur = s; cur != g; cur = nextr[cur][g]) {
        path.push_back(cur);
    }
    path.push_back(g);
    repd(i, 1, path.size()) {
        cnt[path[i - 1]][path[i]] = false;
    }
}
int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<ll>> d(N, vector<ll>(N, INF));
    nextr = vector<vector<ll>>(N, vector<ll>(N, 0));
    cnt = vector<vector<bool>>(N, vector<bool>(N, false));

    rep(i, N) d[i][i] = 0;
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        d[a][b] = c;
        d[b][a] = c;
        cnt[a][b] = true;
        cnt[b][a] = true;
    }

    rep(i, N) {
        rep(j, N) {
            nextr[i][j] = j;
        }
    }

    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    nextr[i][j] = nextr[i][k];
                }
            }
        }
    }

    ll ans = 0;
    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;
            path(i, j);
        }
    }

    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;
            if (cnt[i][j]) ans++;
        }
    }

    cout << ans / 2 << endl;
    return 0;
}