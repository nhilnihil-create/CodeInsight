#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] == i + 1) {
            swap(a[i], a[i + 1]);
            ++ans;
        }
    }
    if (a[n - 1] == n) {
        ++ans;
    }
    cout << ans;
    return 0;
}