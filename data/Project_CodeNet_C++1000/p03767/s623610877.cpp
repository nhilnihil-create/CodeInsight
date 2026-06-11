#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n;
    cin>>n;
    vector<ll> a(3*n);
    rep(i,3*n)cin>>a[i];
    sort(a.rbegin(), a.rend());
    
    ll ans = 0;
    
    rep(i,n)ans += a[2*i+1];
    cout << ans << endl;
    return 0;
}