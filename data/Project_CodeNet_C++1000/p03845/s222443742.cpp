#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
#define v(i) vector<i>
#define vv(i) vector<vector<i>>
// cin.eof() 入力個数の問題
// int num = atoi(string.c_str()); 文字列の整数変換

int main() {
ll n;cin>>n;
ll t[n]; rep(i,n) cin>>t[i];
ll m;cin>>m;
ll p[m],x[m];
rep(i,m){
    cin>>p[i]>>x[i];
}
rep(i,m){
    ll ans = x[i];
    rep(j,n){
        if(j == p[i]-1) continue;
        ans += t[j];
    }
    cout<<ans<<endl;
}

   return 0;
}
