#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, t;
    cin >> n >> t;
    long long a[n], s = t;
    for (long long i = 0; i < n; i++) cin >> a[i];
    if (n > 1)
        for (long long i = 1; i < n; i++) s += min(a[i] - a[i - 1], t);
    cout << s;
}