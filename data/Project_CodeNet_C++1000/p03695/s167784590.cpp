#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long a[n], c[9], t = 0;
    for (long long i = 0; i < 9; i++) c[i] = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] >= 3200) c[8]++;
        else c[a[i] / 400]++;
    }
    for (long long i = 0; i < 8; i++)
        if (c[i] > 0) t++;
    cout << max(t, (long long) 1) << ' ' << t + c[8];
}