#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> data(2 * n);
    for (auto &v : data)
        cin >> v;
    sort(data.begin(), data.end());
    long long ans = 0;
    for (int i = 0 ; i < 2 * n ; i += 2)
        ans += data[i];
    cout << ans << '\n';
}
