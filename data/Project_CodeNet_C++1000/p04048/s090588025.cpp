#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pb emplace_back

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    int ans = n;
    int a = x;
    int b = n - x;
    while (a != 0)
    {
        int k = b / a;
        ans += a * k * 2;
        int c = a;
        a = b % a;
        b = c;
    }
    ans -= b;
    cout << ans;
}
