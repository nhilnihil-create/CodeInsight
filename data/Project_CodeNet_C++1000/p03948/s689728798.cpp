#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, t; cin >> n >> t;
    vector<int> as(n);
    for (int i = 0; i < n; i++) cin >> as[i];

    int ans = 0;
    for (auto &a: as) {
        static int m = inf, benefit = 0;

        int diff = a - m;
        if (diff > benefit) {
            benefit = diff;
            ans = 1;
        } else if (diff == benefit) {
            ans++;
        }
        m = min(m, a);
    }
    cout << ans << endl;
    return 0;
}
