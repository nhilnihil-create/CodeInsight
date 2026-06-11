#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using Graph = vector<vector<pii>>;
const int MOD = 1e9 + 7;

struct prog {
    int s, t, c;
};

bool operator<(prog a, prog b) {
    return (a.c == b.c ? a.s < b.s : a.c < b.c);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W, N;
    cin >> H >> W >> N;

    vector<vector<int>> ans(H, vector<int>(W));
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        for (int j = cnt; j < cnt + a; ++j)
            ans[j / W][j % W] = i + 1;
        cnt += a;
    }

    for (int i = 0; i < H; ++i) {
        if (i % 2 == 0) {
            for (auto j = ans[i].begin(); j != ans[i].end(); ++j)
                cout << *j << ' ';
        }
        else {
            for (auto j = ans[i].rbegin(); j != ans[i].rend(); ++j)
                cout << *j << ' ';
        }
        cout << '\n';
    }

    return 0;
}
