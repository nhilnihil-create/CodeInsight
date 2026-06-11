#include <bits/stdc++.h>
using namespace std;
int main() {
    long n;
    cin >> n;
    long a[n + 1];
    for (long i = 1; i <= n; i++) cin >> a[i];
    if (n % 2 == 0)
    {
        for (long i = n; i >= 2; i = i - 2) cout << a[i] << ' ';
        for (long i = 1; i < n; i = i + 2) cout << a[i] << ' ';
    }
    else
    {
        for (long i = n; i >= 1; i = i - 2) cout << a[i] << ' ';
        for (long i = 2; i < n; i = i + 2) cout << a[i] << ' ';
    }
}