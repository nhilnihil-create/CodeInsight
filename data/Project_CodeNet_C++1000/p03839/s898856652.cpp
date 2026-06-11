#include <iostream>
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    long long s[n+1], L[n+1], R[n+1];
    s[0] = L[0] = R[n] = 0;
    for (int i = 0; i < n; i++) {
        s[i+1] = s[i] + a[i];
        L[i+1] = L[i] + max(0, a[i]);
        R[n-i-1] = R[n-i] + max(0, a[n-i-1]);
    }
    long long ans = 0;
    for (int i = 0; i+k <= n; i++)
        ans = max(ans, max(0LL, s[i+k] - s[i]) + L[i] + R[i+k]);
    cout << ans << endl;
}
