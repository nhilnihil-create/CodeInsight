#include <bits/stdc++.h>
using namespace std;

#define    ll     long long int

const int N = 55;
int ara[N];
int n, a;

ll dp[55][5111];

ll go(int at, int sum)
{
    if (at == n + 1) {
        if (sum == 0) return 1;
        return 0;
    }
    int offset = sum;
    if (sum < 0) {
        offset = 5000 + sum;
    }
    if (dp[at][offset] != -1) {
        return dp[at][offset];
    }
    ll res = go(at + 1, sum) + go(at + 1, sum + ara[at]);
    dp[at][offset] = res;
    return res;
}

int main( )
{
    cin >> n >> a;
    int i, j, k;
    for (i = 1; i <= n; i++) {
        cin >> ara[i];
        ara[i] -= a;
    }
    memset(dp, -1, sizeof dp);
    ll s = go(1, 0);
    cout << s - 1 << '\n';
    return 0;
}
