#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    ll ans=0;
    for(int i=n-1;i>=0;i--){
        a[i]+=ans;
        ll now=0;
        if(a[i]%b[i]!=0){
            now=b[i]-a[i]%b[i];
        }
        ans+=now;
    }
    cout<<ans<<endl;
}