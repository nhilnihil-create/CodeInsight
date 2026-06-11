#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) a[i] = a[i]-1;
    int ans = 1;
    int p1=a[0];
    rep(i,100000){
        if(p1 == 1){
            cout << ans << endl;
            return 0;
        }
        p1 = a[p1];
        ans++;
    }
    cout << -1 << endl;
    return 0;
}