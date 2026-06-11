#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int n;
    cin >> n;
    map<ll,int> mp;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    ll x = -1,y = 0;
    sort(a.rbegin(),a.rend());
    rep(i,n-1){
        if(a[i] != a[i+1]) continue;
        if(x == -1){
            x = a[i];
            i++;
        }
        else{
            y = a[i];
            break;
        }
    }
    ll ans = x*y;
    cout << ans << endl;
}