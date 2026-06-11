#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e5 * 2 + 100, INF = 1e9 + 10, MOD = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, m, psh[SIZE * 8], tree[SIZE * 8];
vector<vector<pair<ll, ll>>> add;

void input() {
    cin >> n >> m;

    add.resize(m + 1);
    for (int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;

        add[r - l + 1].push_back({ l, r });
    }
}

void p(int v) {
    tree[v * 2 + 1] += psh[v];
    tree[v * 2 + 2] += psh[v];
    psh[v * 2 + 1] += psh[v];
    psh[v * 2 + 2] += psh[v];

    psh[v] = 0;
}

void upd(int v, int l, int r, int askl, int askr, int val) {
    if (l >= askr || r <= askl) return;

    if (l >= askl && r <= askr) {
        psh[v] += val;
        return;
    }

    int mid = (l + r) / 2;
    upd(v * 2 + 1, l, mid, askl, askr, val);
    upd(v * 2 + 2, mid, r, askl, askr, val);
}

ll get(int v, int l, int r, int pos) {
    if (l == r - 1) {
        return psh[v];
    }
    else {
        int mid = (l + r) / 2;
        if (pos < mid) {
            return get(v * 2 + 1, l, mid, pos) + psh[v];
        }
        else {
            return get(v * 2 + 2, mid, r, pos) + psh[v];
        }
    }
}

void sol() {
    ll longer = n;

    for (int i = 1; i <= m; i++) {
        ll ans = longer;
        for (int j = 0; j <= m; j += i) {
            ans += get(0, 0, m + 1, j);
        }

        for (auto cur : add[i]) {
            upd(0, 0, m + 1, cur.first, cur.second + 1, 1);
            longer--;
        }
        cout << ans << "\n";
    }
}

int main()
{
    fastInp;

    ll t = 1;

    while (t--) {
        input();
        sol();
    }

    return 0;
}