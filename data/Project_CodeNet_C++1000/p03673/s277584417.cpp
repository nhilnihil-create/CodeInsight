#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    ll guu = 0;
    if (n % 2 == 0) guu = 1;
    else guu = 0;
    ll dir = 0;
    ll posi = n-1;
    for (int i = 0; i < n; ++i) {
        cout << a[posi] << " ";
        if (dir == 0) {
            posi -= 2;
        }
        else {
            posi += 2;
        }
        if (posi < 0) {
            dir = 1;
            if (guu) posi = 0;
            else posi = 1;
        }
    }



}
