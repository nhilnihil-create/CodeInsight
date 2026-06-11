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

int v[N_MAX * 3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n * 3; i++)
        cin >> v[i];
    sort(v + 1, v + n * 3 + 1);
    ll ans = 0;
    for(int i = n + 1; i <= n * 3; i += 2)
        ans += v[i];
    cout << ans << "\n";
    return 0;
}
