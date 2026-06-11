#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    ll n,k;
    cin >> n >> k;
    ll ans = 1;
    rep(i,n){
        if(i == 0) ans *= k;
        else ans *= k-1;
    }
    cout << ans << endl;
    return 0;
}