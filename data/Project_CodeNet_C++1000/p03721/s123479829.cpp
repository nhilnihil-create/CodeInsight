#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, k;
    cin >> n >> k;
    long long a[n], b[n], c[1000000];
    for (long long i = 0; i < 1000000; i++) c[i] = 0;
    for (long long i = 0; i < n; i++) 
    {
        cin >> a[i] >> b[i];
        c[a[i]] += b[i];
    }
    for (long long i = 0; i < 1000000; i++)
    {
        k -= c[i];
        if (k <= 0)
        {
            cout << i;
            break;
        }
    }
}