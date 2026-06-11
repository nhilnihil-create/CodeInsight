//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

ll mul(ll x){
    ll sum=1;
    for(int i=1;i<=x;i++){
        sum*=i;
        sum%=mod;
    }
    return sum;
}
int main(){
    ll n,m; cin>>n>>m;
    if(abs(n-m)>1){
        cout<<0<<endl;
        return 0;
    }
    ll ans=mul(n)*mul(m)%mod;
    if(n-m==0){
        ans*=2;
        ans%=mod;
    }
    cout<<ans<<endl;
}






