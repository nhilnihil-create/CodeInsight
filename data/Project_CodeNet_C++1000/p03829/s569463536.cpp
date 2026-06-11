#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    ll x[n];
    for(ll i=0;i<n;i++) cin >> x[i];
    ll res=0;
    for(ll i=0;i<n-1;i++){
        if((x[i+1]-x[i])*a<=b) res+=(x[i+1]-x[i])*a;
        else res+=b;
    }
    cout << res << endl;
}
