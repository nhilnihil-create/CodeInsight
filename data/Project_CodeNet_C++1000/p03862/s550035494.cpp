//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;


int main(){
    ll n,x; cin>>n>>x;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    ll ans=0;
    rep(i,n-1){
        if(a[i]+a[i+1]<=x)continue;
        ll mn=a[i]+a[i+1]-x;
        ans+=mn;
        if(a[i+1]>=mn)a[i+1]-=mn;
        else {
            a[i]-=a[i]-x;
            a[i+1]=0;
        }
    }
    cout<<ans<<endl;
}






