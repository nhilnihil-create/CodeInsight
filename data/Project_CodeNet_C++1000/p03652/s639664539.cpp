#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 305;

int n, m;
bitset<N> val;

int grid[N][N];

map<int, int> cnt;
vector<pii> loc[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    val.set();
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> grid[i][j];
            if (!j) {
                ++cnt[grid[i][j]];
                loc[grid[i][j]].push_back({i, j});
            }
        }
    }

    int ans = n;
    for (int i = 0; i < m; ++i) {
        int mi, mc = 0;
        for (auto j : cnt) {
            if (j.second > mc) {
                mi = j.first;
                mc = j.second;
            }
        }
        
        val[mi] = false;
        if (mc) ans = min(ans, mc);
        for (auto j : loc[mi]) {
            int x = j.first, y = j.second + 1;
            for (; y < m; ++y) {
                if (val[grid[x][y]]) {
                    loc[grid[x][y]].push_back({x, y});
                    ++cnt[grid[x][y]];
                    break;
                }
            }
        }
        cnt[mi] = 0;
    }
    cout << ans;
}
