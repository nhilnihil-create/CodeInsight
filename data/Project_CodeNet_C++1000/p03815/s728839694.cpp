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
    ll n; cin >> n;
    ll c = n / 11 * 2;
    n = n - (n / 11 * 11);
    if (n == 0) {
        cout << c << endl;
        return 0;
    }
    cout << c + (n > 6) + 1 << endl;
    return 0;
}