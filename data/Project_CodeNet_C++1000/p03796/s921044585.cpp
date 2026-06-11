#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, mod = 1000000007;
    long long f = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        f *= i;
        f %= mod;
    }
    cout << f;
}