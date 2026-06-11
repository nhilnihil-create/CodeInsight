#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

const ll mod=1e9+7;

void Eratos(vector<bool> &IsPrime,ll n){
    rep(i,n) IsPrime[i]=1;
    IsPrime[0]=IsPrime[1]=0;
    for(ll i=2;i*i<n;i++){
        if(IsPrime[i]){
            for(ll j=i;i*j<n;j++){
                IsPrime[i*j]=0;
            }
        }
    }
}

int main(){
    ll n;
    cin>>n;
    vector<bool> IsPrime(n+1);
    Eratos(IsPrime,n+1);
    vector<ll> cnt(n+1,0);
    for(ll i=2;i<=n;i++){
        if(IsPrime[i]){
            for(ll j=i;j<=n;j*=i){
                cnt[i]+=n/j;
            }
        }
    }
    ll ans=1;
    rep(i,n+1){
        if(cnt[i]!=0){
            ans*=cnt[i]+1;
            ans%=mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}