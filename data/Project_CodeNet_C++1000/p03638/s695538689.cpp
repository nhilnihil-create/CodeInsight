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

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<int>> c(h, vector<int>(w, 0));

    int v = 0;
    rep(i, h) {
        int j = 0;
        while(j < w) {
            if (a[v] == 0) {
                ++v;
            }
            c[i][j] = v + 1;
            --a[v];
            ++j;
        }
    }

    rep(i, h) {
        rep(j, w) {
            if (i % 2 == 0) {
                cout << c[i][j] << " ";
            }
            else {
                cout << c[i][w - 1 - j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}