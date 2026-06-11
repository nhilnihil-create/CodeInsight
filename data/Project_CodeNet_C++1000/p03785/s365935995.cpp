#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    int i;
    for(i = 0; i < n; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    int ans = 0;
    for(i = 0; i < n; i++) {
        int start = i;
        while(i < n && t[i] - t[start] <= k && i - start < c) {
            i++;
        }
        ans++;
        i--;
    }
    cout << ans << endl;
}
