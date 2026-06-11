#include <bits/stdc++.h>
#define ll long long int
#define mod_ceil(a, b) (a % b) ? a / b + 1 : a / b
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, t;
    cin >> n >> t;
    vector<ll> A(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    ll ans = t;
    for (ll i = 0; i < n - 1; i++)
    {
        ans += min(t, A[i + 1] - A[i]);
    }
    cout << ans << endl;
}