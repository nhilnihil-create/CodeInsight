#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, C, k; cin >> n >> C >> k;
    vector<int> t(n);
    rep(i, n) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int start = i;
        ans++;
        while (i-start < C&& t[i] <= t[start]+k && i < n) {
            i++;
        }
        i--;
    }
    cout << ans << endl;
}