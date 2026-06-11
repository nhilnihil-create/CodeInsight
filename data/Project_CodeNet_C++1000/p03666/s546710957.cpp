#include <bits/stdc++.h>

///    ____ ____ ____ ____ ____
///   ||a |||t |||o |||d |||o ||
///   ||__|||__|||__|||__|||__||
///   |/__\|/__\|/__\|/__\|/__\|
///

using namespace std;

long long n, A, B, C, D;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> A >> B >> C >> D;
    for(long long m = 0; m <= n - 1; m++)
    {
        if(-D * m + C * (n - 1 - m) <= B - A && B - A <= -C * m + D * (n - 1 - m))
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
