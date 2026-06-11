#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, m;
    cin >> n >> m;
    long long a[n], b[n], c[m], d[m], l[m], k, r;
    for (long long i = 0; i < n; i++) cin >> a[i] >> b[i];
    for (long long i = 0; i < m; i++) cin >> c[i] >> d[i];
    for (long long i = 0; i < n; i++)
    {
        k = 1e11;
        for (long long j = 0; j < m; j++)
        {
            l[j] = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if (k > l[j])
            {
                k = l[j];
                r = j + 1;
            }
        }
        cout << r << endl;
    }
}