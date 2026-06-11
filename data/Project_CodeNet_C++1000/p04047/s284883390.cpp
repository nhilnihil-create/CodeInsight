#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<ll> a(2*n);
    for(ll i=0;i<2*n;++i){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    ll ans=0;
    for(ll i=0;i<2*n;++i){
        if(i%2==1){
            continue;
        }
        ans+=a[i];
    }
    cout<<ans<<endl;

    return 0;
}