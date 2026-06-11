#include <bits/stdc++.h>
#define rep(i, n) for (ll(i) = 0; (i) < (n); (i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
int main()
{
    int k, s;
    cin >> k >> s;
    ll ans = 0;
    for (int i = 0; i <= k && i <= s; i++)
    {
        for (int j = 0; j + i <= s && j <= k; j++)
        {
            if (s - (i + j) >= 0 && s - (i + j) <= k)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}