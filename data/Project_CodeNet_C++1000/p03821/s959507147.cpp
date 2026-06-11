#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,c=0; cin >> n;
    ll a[n],b[n];
    rep(i,n) cin >> a[i] >> b[i];

    ll x;
    for (ll i = n-1; i >= 0; i--){
        a[i] += c;
        x = a[i]%b[i];
        if (x > 0){
            if (a[i] < b[i]) c += b[i] - a[i];
            else if (a[i] > b[i]) c += b[i] - x;
        }
    }
    cout << c << "\n";
}