#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

const ll mod=1e9+7;

template<typename T>inline bool chmax(T &a,const T &b){if(a>=b){return false;}a=b;return true;}
template<typename T>inline bool chmin(T &a,const T &b){if(a<=b){return false;}a=b;return true;}

/*-------------------------------------------*/


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,k;
    cin>>n>>k;
    vector<ll>a(n),sum1(n+1),sum2(n+1);
    ll ans=0;

    rep(i,n){
        cin>>a[i];
        sum1[i+1]=sum1[i]+a[i];
        sum2[i+1]=sum2[i]+max(0ll,a[i]);
    }

    rep(i,n-k+1){
        chmax(ans,sum2[i]-sum2[0]+max(0ll,sum1[i+k]-sum1[i])+sum2[n]-sum2[i+k]);
    }

    cout<<ans<<endl;
}