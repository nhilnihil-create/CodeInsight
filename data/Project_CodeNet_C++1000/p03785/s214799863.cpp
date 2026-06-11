#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    for (int &i: t) cin >> i;
    sort(t.begin(), t.end());
    int ans = 1;
    int cnt = 1;
    int fride = t[0];
    for (int i=1; i<n; ++i) {
        if (cnt == c) {
            ans++;
            cnt = 1;
            fride = t[i];
        }
        else if (t[i] > fride + k) {
            ans++;
            cnt = 1;
            fride = t[i];
        }
        else cnt++;
    }
    cout << ans << endl;
}