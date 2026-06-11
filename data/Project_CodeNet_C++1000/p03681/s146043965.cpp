#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
    long long n, m, f = 1;
    cin >> n >> m;
    if (abs(n - m) > 1) cout << '0';
    else
    {
        if (m == n)
        {
            for (int i = 2; i <= n; i++)
                f = (f * i) % mod;
            f = (f * f) % mod;    
            f = f * 2;
        }
        else
        {
            for (int i = 2; i <= min(m, n); i++)
                f = (f * i) % mod;
            f = (f * f) % mod;
            f = (f * max(m, n)) % mod;
        }
        cout << (f + mod) % mod;
    }
}