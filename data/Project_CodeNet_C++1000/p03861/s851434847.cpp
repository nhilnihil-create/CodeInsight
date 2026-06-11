#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める
ll f(ll n, ll x){
    if(n != -1) return n/x+1;
    else return 0;
}
int main()
{
    ll a,b,x;
    cin >> a >> b >> x;
    ll ans;
    ans = f(b,x) - f(a-1,x);
    cout << ans << endl;
    return 0;
}