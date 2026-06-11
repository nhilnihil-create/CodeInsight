#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> interval(100005);
    rep(i,n){
        if(a[i] != 0) interval[a[i]-1]++;
        interval[a[i]]++;
        interval[a[i]+1]++;
    }
    ll maxcnt = 0;
    rep(i,100002){
        maxcnt = max(maxcnt, interval[i]);
    }
    cout << maxcnt << endl;
    return 0;
}
