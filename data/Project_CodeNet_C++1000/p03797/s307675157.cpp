#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define inf LLONG_MAX
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll n, m;
    cin >> n >> m;
    if (2 * n >= m) {
        cout << m / 2 << endl;
        return 0;
    }
    ll count = n;
    m -= 2 * n;
    count += m / 4;
    cout << count << endl;
    return 0;
}