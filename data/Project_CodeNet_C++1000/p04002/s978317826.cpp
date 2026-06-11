#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)((x).size())
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

const int MOD = 1e9 + 7, MAXN = 1e6 + 10, INF = 1e18 + 10, BASE = 37;

void solve() {
    int h, w, n;
    cin >> h >> w >> n;
    vec<pii> p(n);
    cin >> p;

    if (n == 0) {
        cout << (h - 2) * (w - 2) << endl;
        for (int i = 1; i <= 9; ++i) {
            cout << 0 << endl;
        }
        return;
    }

    set<pii> se;
    for (auto it : p) {
        se.insert(it);
    }

    set<pii> S;
    for (auto it : p) {
        for (int i = it.x - 2; i <= it.x; ++i) {
            for (int j = it.y - 2; j <= it.y; ++j) {
                if (1 <= i && i <= h - 2 && 1 <= j && j <= w - 2) {
                    S.insert({i, j});
                }
            }
        }
    }

    cout << (h - 2) * (w - 2) - sz(S) << endl;
    vec<int> cnt(10);
    sort(all(p));

    for (auto it : p) {
        vec<pii> pos;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int x1 = it.x - i, x2 = it.x + (3 - i - 1);
                int y1 = it.y - j, y2 = it.y + (3 - j - 1);
                if (1 <= x1 && x2 <= h && 1 <= y1 && y2 <= w) {
                    int count = 0;
                    for (int i1 = x1; i1 <= x2; ++i1) {
                        for (int j1 = y1; j1 <= y2; ++j1) {
                            if (se.count({i1, j1})) {
                                count++;
                            }
                        }
                    }
                    cnt[count]++;
                }
            }
        }
    }

    for (int i = 1; i <= 9; ++i) {
        cout << cnt[i] / i << endl;
    }
}