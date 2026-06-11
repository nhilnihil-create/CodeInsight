#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n; cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0; i<n; i++) cin>>a[i]>>b[i];
    ll ans=0,sum=0,res;
    for(int i=n-1; i>=0; i--) {
        res = b[i] - (a[i]+sum) % b[i];
        res %= b[i];
        ans += res;
        sum += res;
    }
    cout<<ans;
}