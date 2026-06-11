#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);


int main(void)
{
    ll n,p,cnt=0,odd=0,even=0;
    cin>>n>>p;
    rep(i,n){
        ll a;
        cin>>a;
        if(a%2) odd++;
        else even++;
    }
    ll ans=1;
    if(even==n){
        if(p) ans=0;
        else{
            rep(i,n) ans*=2; 
        }
    }else{
        rep(i,n-1) ans*=2;
    }
    cout<<ans<<endl;
    return 0;
}