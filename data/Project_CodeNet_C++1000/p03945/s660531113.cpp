#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    string s;
    cin>>s;
    ll n=s.length();
    ll ans=0;
    rep(1,i,n)if(s[i]!=s[i-1])++ans;
    cout<<ans;
}
