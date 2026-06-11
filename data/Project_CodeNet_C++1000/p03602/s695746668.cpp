#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define ternary(condition, x, y) ((condition) ? x : y) 
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)

const static llong MOD = 1000000000 + 7;
const static int dy[] = {0, 1, 0, -1};
const static int dx[] = {1, 0, -1, 0};

const int N = 300;
llong dist[N][N], a[N][N];
bool check_road_needed[N][N];

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    rep(i, n) {
        rep(j, n) {
            cin >> a[i][j];
            dist[i][j] = a[i][j];
            check_road_needed[i][j] = true;
        }
    }

    rep(i, n) {
        rep(j, n) {
            rep(k, n) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    rep(i, n) {
        rep(j, n) {
            if (dist[i][j] != a[i][j]) {
                cout << -1 << endl;
                return 0;
            }

            rep(k, n) {
                if (a[i][j] == a[i][k] + a[k][j] && i != k && j != k) check_road_needed[i][j] = false;
            }
        }
    }

    llong ans = 0;
    rep(i, n) {
        rep(j, n) {
            if (check_road_needed[i][j]) ans += a[i][j];
        }
    }

    cout << ans / 2 << endl;

    return 0;
}