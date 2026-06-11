#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> cumsum(n + 1);
    cumsum[0] = 0;
    rep(i, 0, n)
    {
        int a;
        cin >> a;
        cumsum[i + 1] = a + cumsum[i];
    }

    ll ans = 1000000000000000;
    rep(i, 1, n)
        ans = min(ans, abs(2 * cumsum[i] - cumsum[n]));

    cout << ans << endl;
    return 0;
}