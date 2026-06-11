#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int w,h,n;
    cin >> w >> h >> n;
    int l = 0, r = w, d = 0, u = h;
    vector<int>x(n);
    vector<int>y(n);
    vector<int>a(n);
    rep(i,n) {
        cin >> x[i] >> y[i] >> a[i];
    }
    rep(i,n){
        if(a[i] == 1 && x[i] > l) l = x[i];
        if(a[i] == 2 && x[i] < r) r = x[i];
        if(a[i] == 3 && y[i] > d) d = y[i];
        if(a[i] == 4 && y[i] < u) u = y[i];
    }
    
    if(r-l <= 0 || u-d <= 0) cout << 0 << endl;
    else cout << (r-l)*(u-d) << endl;
    return 0;
}