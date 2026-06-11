#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,s,n) for(int i = (s); i < (n); ++i)
#define ll long long
#define ld long double
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n; cin>>n;
    vector<ll> a(n),b(n);
    rep(i,n){
        cin>>a[i];
        b[i]=a[i];
    }
    
    ll ans=0,res1=0,res2=0;

    rep(i,n){
        if(i%2==0){
            if(a[i]<=0) res1+=(1-a[i]),a[i]=1;
            if(b[i]>=0) res2+=(b[i]+1),b[i]=-1;
        }else{
            if(a[i]>=0) res1+=(1+a[i]),a[i]=-1;
            if(b[i]<=0) res2+=(1-b[i]),b[i]=1;
        }

        if(i!=n-1){
            a[i+1]+=a[i];
            b[i+1]+=b[i];
        }
    }

    ans=min(res1,res2);
    cout<<ans<<endl;
    return 0;
}