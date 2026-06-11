#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long t[n], a[n];
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> a[i];
    }
    long lt = 1, la = 1;
    for (int i = 0; i < n; i++) {
        long long k = max((lt + t[i] - 1) / t[i], (la + a[i] - 1) / a[i]);
        lt = k * t[i];
        la = k * a[i];
    }
    cout << lt + la << endl;
}