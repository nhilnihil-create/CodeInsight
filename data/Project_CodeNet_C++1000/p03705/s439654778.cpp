/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a >> b;
    cout << max(0LL, (a + (n - 1) * b) - ((n - 1) * a + b) + 1) << "\n";
    return 0;
}
