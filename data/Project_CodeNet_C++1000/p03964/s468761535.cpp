#include <bits/stdc++.h>
using namespace std;
long long intceil(long long a, long long b) {
    if (a % b == 0) return a / b;
    else return a / b + 1;
}
int main() {
    long long n;
    cin >> n;
    long long a[n], t[n], k, p = 1, q = 1;
    for (long long i = 0; i < n; i++) cin >> t[i] >> a[i];
    for (long long i = 0; i < n; i++)
    {
        k = max(intceil(p, t[i]), intceil(q, a[i]));
        p = k * t[i];
        q = k * a[i];
    }
    cout << p + q;
}