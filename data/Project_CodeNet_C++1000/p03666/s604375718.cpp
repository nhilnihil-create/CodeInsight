#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    long long q = abs(a-b); n--;
    for (long long i = 0; i <= n; i++) {
        long long u = c * (n-i);
        long long v = d * (n-i);
        long long x = -c * i;
        long long y = -d * i;
        if (u+y <= q && q <= v+x) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}