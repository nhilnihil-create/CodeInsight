#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    long n,a,b,ans=0;
    cin >> n >> a >> b;
    long x[n];
    rep(i,n) cin >> x[i];
    rep(i,n-1) ans += min((x[i+1]-x[i])*a,b);
    cout << ans << endl;
}