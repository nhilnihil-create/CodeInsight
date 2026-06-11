#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr int MN = 505;

int ans[MN*MN];
ii x[MN];

int main() {
    if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);

    int N; cin >> N;
    set<int> S;
    for (int i = 0; i < N*N; ++i) S.insert(i);
    for (int i = 0; i < N; ++i) {
        cin >> x[i].f;
        S.erase(--x[i].f), ans[x[i].f] = x[i].s = i;
    }
    sort(x, x+N);
    for (int i = 0; i < N; ++i) {
        int j = 0;
        while (S.size() && *begin(S) < x[i].f && j < x[i].s)
            ans[*begin(S)] = x[i].s, S.erase(begin(S)), ++j;
        if (j < x[i].s) {
            cout << "No";
            return 0;
        }
    }
    for (int i = 0; i < N; ++i) {
        int j = 0;
        auto it = S.upper_bound(x[i].f);
        while (it != end(S) && j < N-x[i].s-1)
            ans[*it] = x[i].s, it = S.erase(it), ++j;
        if (j < N-x[i].s-1) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < N*N; ++i) cout << ans[i]+1 << ' ';
}