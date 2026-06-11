#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
using namespace std;
typedef vector<int> vi;
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
const int maxn = 110000, maxd = 11;
int c[maxn][maxd];
int col[maxn];
vector<int> e[maxn];
int main() {
    int n, m, q;
    cin >> n >> m;
    forn(i, m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        e[a].pb(b);
        e[b].pb(a);
    }
    cin >> q;
    forn(i, q) {
        int v, d;
        cin >> v >> d >> col[i + 1];
        --v;
        c[v][d] = i + 1;
    }
    ford(i, maxd - 1) forn(v, n) for (int u: e[v]) uax(c[u][i], c[v][i + 1]);
    forn(v, n) {
        int res = 0;
        forn(d, maxd) uax(res, c[v][d]);
        cout << col[res] << '\n';
    }
    return 0;
}