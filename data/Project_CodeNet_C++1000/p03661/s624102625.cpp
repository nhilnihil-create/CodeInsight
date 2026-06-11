#include <bits/stdc++.h>
using namespace std;

#define   ll     long long int

const int N = 200005;
ll ara[N];
ll lft[N];
ll rht[N];

int main( )
{
    ll n, i, j, k, mn = 1e18;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> ara[i];
        lft[i] = lft[i - 1] + ara[i];
    }
    for (i = n; i >= 1; i--) {
        rht[i] = rht[i + 1] + ara[i];
    }
    for (i = 2; i <= n; i++) {
        mn = min(mn, abs(lft[i - 1] - rht[i]));
    }
    cout << mn << '\n';
    return 0;
}

