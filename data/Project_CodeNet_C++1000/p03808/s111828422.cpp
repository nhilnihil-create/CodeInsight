#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);
    ll s = 0, t = n * (n + 1) / 2;
    rep(i, n)
    {
        cin >> a[i];
        s += a[i];
    }

    if (s % t != 0)
    {
        cout << "NO" << endl;
        return 0;
    }

    s /= t;

    rep(i, n) if ((a[(i + 1) % n] - a[i % n] - s) % n != 0 || a[(i + 1) % n] - a[i % n] > s)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;

  

    return 0;
}
