#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define $(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define x first
#define y second
#define int long long
#define double long double
#define pii pair<int, int>
#define pb push_back
#define vec vector
#define beg begin
#define dbg(x) cerr << #x << " = " << x << endl;

template<class T> ostream& operator<<(ostream &str, vector<T> &a) {
    for (auto &i : a) {
        str << i << " ";
    }
    return str;
}

template<class T> istream& operator>>(istream &str, vector<T> &a) {
    for (auto &i : a) {
        str >> i;
    }
    return str;
}

template<class T> ostream& operator<<(ostream &str, pair<T, T> &a) {
    str << a.first << " " << a.second;
    return str;
}

template<class T> istream& operator>>(istream &str, pair<T, T> &a) {
    str >> a.first >> a.second;
    return str;
}

void solve(); signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\artma\\CLionProjects\\problems\\input.txt", "r", stdin);
#endif
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(6);
    solve();
    return 0;
}

const int MOD = 1e9 + 7, MAXN = 1e5 + 10, INF = 1e18 + 10, BASE = 37;
int N, L, Q;

void dfs(int v, int p, vec<vec<int>> &g, vec<vec<int>> &mx, vec<vec<int>> &pr) {
    mx[v][0] = p;
    pr[v][0] = p;
    for (int k = 1; k < 30; ++k) {
        pr[v][k] = pr[pr[v][k - 1]][k - 1];
    }
    for (int k = 1; k < 30; ++k) {
        mx[v][k] = max(mx[v][k - 1], mx[pr[v][k - 1]][k - 1]);
    }
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v, g, mx, pr);
        }
    }
}

int query(int a, int b, vec<vec<int>> &mx, vec<vec<int>> &pr) {
    int s = 0;
    for (int k = 29; k >= 0; --k) {
        if (mx[a][k] < b) {
            s += (1ll << k);
            a = pr[a][k];
        }
    }
    s++;
    return s;
}

void solve() {
    cin >> N;
    vec<int> x(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> x[i];
    }
    cin >> L >> Q;

    vec<vec<int>> g1(MAXN), g2(MAXN), mx1(MAXN, vec<int>(30)), pr1(MAXN, vec<int>(30)), mx2(MAXN, vec<int>(30)), pr2(MAXN, vec<int>(30));
    for (int i = 1; i <= N; ++i) {
        int l = i + 1, r = N + 1;
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (x[mid] - x[i] <= L) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        if (l == N + 1) l = 0;
        g1[l].pb(i);
        g1[i].pb(l);
    }

    dfs(N, 0, g1, mx1, pr1);

    vec<pii> qs(Q);
    vec<int> ans(Q);
    for (int _ = 0; _ < Q; ++_) {
        int a, b;
        cin >> a >> b;
        qs[_] = {a, b};
        if (a < b) {
            ans[_] = query(a, b, mx1, pr1);
        }
    }

    vec<int> y(N + 1);
    y[0] = -INF;
    for (int i = 1; i <= N; ++i) {
        y[i] = -x[N - i + 1];
    }

    for (int i = 1; i <= N; ++i) {
        int l = i + 1, r = N + 1;
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (y[mid] - y[i] <= L) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        if (l == N + 1) l = 0;
        g2[l].pb(i);
        g2[i].pb(l);
    }

    dfs(N, 0, g2, mx2, pr2);

    for (int i = 0; i < Q; ++i) {
        if (qs[i].x > qs[i].y) {
            ans[i] = query(N - qs[i].x + 1, N - qs[i].y + 1, mx2, pr2);
        }
    }

    for (int i = 0; i < Q; ++i) {
        cout << ans[i] << endl;
    }
}