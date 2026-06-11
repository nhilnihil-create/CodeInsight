#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

int main() {
    int k, t;
    cin >> k >> t;
    vector<int> a(t);
    for (int i = 0; i < t; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    int kmax = a[0], kother = 0;
    for (int i = 1; i < t; i++) kother += a[i];
    int ans = 0;
    if (kmax > kother) ans = kmax - kother - 1;
    cout << ans << endl;
    return 0;
}