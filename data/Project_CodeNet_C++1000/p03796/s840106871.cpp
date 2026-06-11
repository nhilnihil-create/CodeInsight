#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ll n;
    ll ans=1;
    cin >> n;

    for (ll i = 1; i < n+1; i++)
    {
        ans = (ans*i)%1000000007;
    }
    cout << ans << endl;
    return 0;
}