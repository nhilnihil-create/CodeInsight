#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n,m;
    cin >> n;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    cin >> m;
    vector<int> p(m),x(m);
    rep(i,m) cin >> p[i] >> x[i];
    ll total = 0;
    rep(i,n) total += t[i];
    rep(i,m){
        cout << total + x[i] - t[p[i]-1] << endl;
    }
    return 0;
}