#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    ll sum = 0;
    for(int i = n-1; i >= 0; i--)
    {
        ll rem = (a[i]+sum) % b[i];
        sum += (b[i] - rem) % b[i];
    }
    cout << sum << endl;
}

