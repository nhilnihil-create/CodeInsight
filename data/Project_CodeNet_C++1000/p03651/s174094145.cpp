#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int g = 0;
    for (int i = 0; i < n; i++) {
        g = gcd(g, a[i]);
    }

    string ans = "IMPOSSIBLE";
    for (int i = 0; i < n; i++) {
        int d = a[i] - k;
        if (d >= 0 && d % g == 0) ans = "POSSIBLE";
    }

    cout << ans << endl;
    return 0;
}
