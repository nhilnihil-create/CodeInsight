#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define re return
#define endl '\n'

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using ld = long double;

template <class T> T abs (T x) { re x > 0 ? x : -x; }
template <class T> T sqr (T x) { re x * x; }

const ld pi = 4 * atan(1.);
const double inf = 1e18 + 7; 
const int N = 3e5 + 17;

int n, m, k;
vii q;

const int lg = 20;
int t[N * lg], L[N * lg], R[N * lg];
int cnt = 1;
int root[N];

int build(int v, int tl, int tr) {
    if (tl == tr) re v;
    int c = (tl + tr) >> 1;
    L[v] = build(++cnt, tl, c);
    R[v] = build(++cnt, c + 1, tr);
    re v;
}

int upd(int v, int tl, int tr, int x, int pos) {   
    int r = ++cnt;
    R[r] = R[v];
    L[r] = L[v];
    t[r] = t[v];
    if (tl == tr) { t[r] += x; return r; }
    int c = (tl + tr) >> 1;
    if (pos > c) R[r] = upd(R[r], c + 1, tr, x, pos);
    else L[r] = upd(L[r], tl, c, x, pos);
    t[r] = t[L[r]] + t[R[r]];
    return r;
}

int get(int v, int tl, int tr, int l, int r) {
    if (!v || tl > r || l > tr) return 0;
    if (l <= tl && tr <= r) return t[v];
    int c = (tl + tr) >> 1;
    return get(L[v], tl, c, l, r) + get(R[v], c + 1, tr, l, r);
}

int func(int x, int y) {
    re get(root[x], 0, m, x, y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int l, r; 
        cin >> l >> r;
        q.pb({l, r});
    }
    sort(all(q));
    root[0] = build(cnt, 0, m);
    int l = 1;
    for (auto p : q) {
        while (l < p.fi) {
            l++;
            root[l] = root[l - 1];
        }
        root[l] = upd(root[l], 0, m, 1, p.se);
    }
    while (l <= m) {
        l++;
        root[l] = root[l - 1];
    }
    for (int i = 1; i <= m; i++) {
        int cur = 0;
        for (int j = 0; j <= m; j += i)
            cur += func(j, min(j + i - 1, m));
        cout << cur << '\n';
    }
}