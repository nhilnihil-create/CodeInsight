#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long> a(n);
    for (long &e : a) cin >> e;
    
    long now = 2;
    long ans = a[0] - 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == now) { now++; continue; }
        if (a[i] % now == 0) {
            a[i] -= (now + 1);
            ans++;
        }
        ans += (a[i] / now);
        a[i] %= now;
        if (a[i] == now) now++;
    }
    
    cout << ans << endl;
    return 0;
}