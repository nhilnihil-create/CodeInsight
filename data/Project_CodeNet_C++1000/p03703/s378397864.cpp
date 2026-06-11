#include <bits/stdc++.h>

using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
const int N = 2e5 + 5;
int fen[N], a[N];

void add(int idx) {
    for (idx++; idx < N; idx += idx&(-idx)) fen[idx]++;
    return ;
}
int get(int idx) {
    int res = 0;
    for (idx++; idx; idx -= idx&(-idx)) res += fen[idx];
    return res;
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k, ans = 0; cin >> n >> k;
    vector <int> vec = {0};
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1] - k, vec.push_back(a[i]);
    sort(all(vec)), vec.resize(unique(all(vec)) - vec.begin());
    for (int i = 0; i <= n; i++) {
        int x = lower_bound(all(vec), a[i]) - vec.begin();
        ans += get(x), add(x);
    }
    cout << ans << "\n";
}
