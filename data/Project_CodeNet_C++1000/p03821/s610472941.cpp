#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    vector<ll>a(n),b(n);
    rep(i,n)cin>>a[i]>>b[i];
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    ll ans=0;
    rep(i,n){
        a[i]+=ans;
        if(a[i]%b[i]!=0)ans+=b[i]-(a[i]%b[i]);
    }
    cout<<ans<<endl;
    return 0;
}