#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> H(n + 1);

    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        H[a]++;
        H[b]++;
    }

    rep(i, n + 1)
    {
        if (H[i] % 2 == 1)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}