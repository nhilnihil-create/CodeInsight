#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,s=0;
    cin >> n;
    vector<ll> a(n),d(n);
    string ans = "YES";
    for(int i = 0;i < n;i ++){
        cin >> a[i];
        if(i) d[i] = a[i]-a[i-1];
        s += a[i];
    }
    d[0] = a[0]-a[n-1];
    if((2*s)%(n*(n+1))) {cout << "NO" << endl;return 0;}
    ll k = (2*s)/(n*(n+1)),sm=0;
    for(int i = 0;i < n;i ++){
        d[i] -= k;
    }
    for(int i = 0;i < n;i ++){
        if(d[i]>0) {ans="NO";break;}
        else {
            ll m;
            if(d[i]%n) {ans="NO";break;}
            else {m=abs(d[i]/n);sm += m;}
        }
    }
    if(sm!=k) ans = "NO";
    cout << ans << endl;
    return 0;
}