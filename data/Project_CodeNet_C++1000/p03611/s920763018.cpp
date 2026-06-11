#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fo(i, a, b) for (ll i = (a); i <= (b); ++i)
#define fd(i, b, a) for (ll i = (b); i >= (a); --i)

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    int ans = 0;
    int a[1000020] = {};

    fo(i, 1, n)
    {
        int x;
        cin >> x;
        a[x]++;
        a[x + 1]++;
        a[x + 2]++;
    }
    fo(j, 0, 1000010) if (ans < a[j]) ans = a[j];
    cout << ans;
}