#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    ll q,h,s,d,n;
    cin>>q>>h>>s>>d>>n;
    if(n%2==0){
        n/=2;
        cout<<min({d*n,s*2*n,h*4*n,q*8*n})<<endl;
    }
    else{
        int x=n/2;
        ll ans=0;
        ans+=min({d*x,s*2*x,h*4*x,q*8*x});
        ans+=min({s,2*h,4*q});
        cout<<ans<<endl;
    }
}
