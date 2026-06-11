#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n); for (auto i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int64_t ans = a.size(), sum = a[0], cnt = 1;
    for (auto i = 0; i < n - 1; i++) {
        if(sum * 2 < a[i + 1]) ans = a.size() - cnt;
        sum += a[i + 1]; cnt++;
//        cout << i << " " << sum << " " << cnt << endl;
    }

    cout << ans << endl;
    return 0;
}