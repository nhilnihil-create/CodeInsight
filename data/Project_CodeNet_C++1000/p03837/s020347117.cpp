#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<string>
#include<cstring>
#include<time.h>
#include<iomanip>
#include<list>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;

#define repi(i,a,b) for(ll i = (a); i < (b); i++)
#define rep(i, n) for(ll i = 0; i < (n); ++i)

ll inf = 1000000000000000;
vector<vector<ll>> d;
vector<vector<unordered_set<ll>>> nxt;
vector<vector<bool>> f;

void ff(ll x, ll y) {
    for (ll z : nxt[x][y]) {
        f[min(z, x)][max(z, x)] = false;
        ff(z, y);
    }
}

int main() {
    ll N, M;
    cin >> N >> M;
    d.resize(N);
    nxt.resize(N);
    f.resize(N);
    rep(i, N) {
        d[i].resize(N);
        nxt[i].resize(N);
        f[i].resize(N);
        rep(j, N) {
            d[i][j] = (i == j ? 0 : inf);
            f[i][j] = false;
        }
    }
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        d[a][b] = c;
        d[b][a] = c;
        f[min(a, b)][max(a, b)] = true;
        nxt[a][b].insert(b);
        nxt[b][a].insert(a);
    }
    rep(k, N)rep(i, N)rep(j, N) {
        if (d[i][j] < d[i][k] + d[k][j] || k == j) continue;
        else if (d[i][j] > d[i][k] + d[k][j]) {
            d[i][j] = d[i][k] + d[k][j];
            nxt[i][j].clear();
        }
        nxt[i][j].insert(nxt[i][k].begin(), nxt[i][k].end());
    }
    rep(i, N - 1)repi(j, i + 1, N) {
        if (d[i][j] == inf) continue;
        ff(i, j);
    }
    ll res = 0;
    rep(i, N - 1)repi(j, i + 1, N)if (f[i][j])res++;
    cout << res << endl;
    return 0;
}

