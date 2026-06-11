#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,p;
    cin>>n>>p;
    vector<ll> a(n);
    bool ok = true;
    for(ll i=0; i<n; i++) {
        cin>>a[i];
        if(a[i] % 2 == 1) ok = false;
    }
    ll ans1 = pow(2,n);
    ll ans2 = pow(2,n-1);
    if(ok) {
        if(p == 0) cout<< ans1 <<endl;
        else cout<< 0 <<endl;
        return 0;
    }
    else {
        cout<< ans2 <<endl;
    }
}