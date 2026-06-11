//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

ll t(ll x){
    ll mul=1;
    rep(i,x){
        mul*=2;
    }
    return mul;
}
int main(){
    ll n,p; cin>>n>>p;
    vector<ll>a(n);
    bool odd=false;
    rep(i,n){
        cin>>a[i];
        if(a[i]%2==1)odd=true;
    }
    ll ans;
    if(!odd){
        if(p==1)ans=0;
        else ans=t(n);
    }
    else{
        ans=t(n-1);
    }
    cout<<ans<<endl;

}






