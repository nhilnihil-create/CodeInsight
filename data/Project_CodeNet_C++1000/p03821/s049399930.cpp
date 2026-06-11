/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 100002;

int n;

ll a[N_MAX], b[N_MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    ll ans = 0;
    for(int i = n; i >= 1; i--)
    {
        a[i] += ans;
        ll k = (a[i] + b[i] - 1) / b[i] * b[i];
        ans += k - a[i];
    }
    cout << ans << "\n";
    return 0;
}
