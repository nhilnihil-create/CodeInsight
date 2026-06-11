#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n, c, k, ans = 1;
    cin >> n >> c >> k;
    int t[n];
    for(int i = 0; i < n; ++i) cin >> t[i];
    sort(t, t+n);

    int limit = t[n-1] - k, num = 1;
    for(int i = n-2; i >= 0; --i) {
        if(t[i] >= limit && num < c) {
            num++;
        } else {
            limit = t[i] - k;
            num = 1;
            ans++;
        }
    }
    
    cout << ans << '\n';

    return 0;
}
