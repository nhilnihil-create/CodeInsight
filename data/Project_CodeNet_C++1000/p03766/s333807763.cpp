#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;
const ll MOD = 1e9 + 7;

int N;
ll res[MAXN];
ll rps[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    rps[N+1] = 0;
    res[N] = 1;
    res[N-1] = N;
    for (int i = N; i >= 0; i--)
    {
        if (i == N)
            res[i] = 1;
        else if (i == N - 1)
            res[i] = N;
        else
        {
            res[i] = (N - 1) * ((ll) N - 1) % MOD;
            res[i] = (res[i] + res[i+1]) % MOD;

            res[i] = (res[i] + rps[i+3]) % MOD;
            res[i] = (res[i] + i + 1) % MOD;
        }
        rps[i] = (res[i] + rps[i+1]) % MOD;
    }
    cout << res[0] << "\n";
}