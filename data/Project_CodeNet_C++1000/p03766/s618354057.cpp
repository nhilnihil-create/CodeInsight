#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1000005;
const long long Mod = 1000000007;

long  long n;
long long f[MaxN];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    long long sum = n;
    f[n] = n;
    for (int i = n - 1; i >= 1; --i)
    {
        f[i] = (sum - f[i + 2] + i + (i != n - 1) + (n - 1) * (n - 1) + Mod * Mod) % Mod;
        sum = (sum + f[i])%Mod;
    }
    cout << f[1];
    return 0;
}