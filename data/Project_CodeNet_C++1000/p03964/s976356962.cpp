#include <bits/stdc++.h>
using namespace std;
void solve () {
    int n;
    cin >> n;
    long long int x = 1;
    long long int y = 1;
    for (int i = 0; i < n; i++) {
        long long int a, b;
        cin >> a >> b;
        long long p  = ( a + x - 1ll) / a;
        long long p2 = (b + y - 1ll) / b;
        p = max (p, p2);
        x = a * p, y = p * b;
    }
    cout << x + y;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
