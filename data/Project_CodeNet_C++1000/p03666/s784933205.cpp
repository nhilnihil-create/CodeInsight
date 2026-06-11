#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    ll n,a,b,c,d,x=0;
    cin>>n>>a>>b>>c>>d;
    rep(i,n) if(a+i*c-(n-i-1)*d<=b&&b<=a+i*d-(n-i-1)*c) x=1;
    if(x) cout<<"YES";
    else cout<<"NO";
}