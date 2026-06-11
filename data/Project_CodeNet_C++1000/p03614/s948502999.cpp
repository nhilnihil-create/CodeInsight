#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int inf = 1e9;
constexpr ll linf = 1e18;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    int ans = 0;
    if (p[n - 1] == n) {
        swap(p[n - 1], p[n - 2]);
        ans++;
    }

    for (int i = 0; i < n - 1; i++) {
        if (p[i] == i + 1) {
            swap(p[i], p[i + 1]);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}