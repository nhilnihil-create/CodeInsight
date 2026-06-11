#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    int f = 1;
    if (v[0] > v[1])
        f = -1;
    else if (v[0] == v[1])
        f = 0;
    int ans = 1;
    for (int i = 1; i < n - 1; i++)
    {
        if (f == 1 && v[i] > v[i + 1])
            f = 0, ans++;
        else if (f == -1 && v[i] < v[i + 1])
            f = 0, ans++;
        else if (f == 0)
        {
            if (v[i] < v[i + 1])
                f = 1;
            else if (v[i] > v[i + 1])
                f = -1;
        }
    }
    cout << ans << endl;
}