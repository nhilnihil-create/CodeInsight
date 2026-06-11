#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ll q,h,s,d,n;
    cin>>q>>h>>s>>d>>n;
    if(d<2*s&&d<4*h&&d<8*q){
        ll ans=n/2*d;
        n=n%2;
        if(s<=2*h&&s<=4*q) cout<<ans+s*n;
        else if(h<=2*q) cout<<ans+h*2*n;
        else cout<<ans+q*4*n;
    }
    else{
        if(s<=2*h&&s<=4*q) cout<<s*n;
        else if(h<=2*q) cout<<h*2*n;
        else cout<<q*4*n;
    }
    cout<<"\n";
}