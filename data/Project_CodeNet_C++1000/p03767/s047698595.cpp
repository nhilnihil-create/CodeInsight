#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(3*n);
    for(int i = 0; i < 3*n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = 0; i < n; i++) ans += a[3*n-2 - i*2];
    cout << ans << endl;
}
