#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] / 2;
        if (i < n - 1 && a[i] % 2 == 1 && a[i + 1] != 0) {
            a[i + 1]++;
        }
    }

    cout << ans << endl;
    return 0;
}
