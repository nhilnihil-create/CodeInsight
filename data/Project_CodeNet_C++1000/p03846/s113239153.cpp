#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

const ll mod=1e9+7;

ll modpow(ll a,ll n){
    if(n==0) return 1;
    if(n==1) return a;
    else if(n%2) return a*modpow(a*a%mod,(n-1)/2)%mod;
    else return modpow(a*a%mod,n/2);
}

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    sort(all(a));
    bool flag=1;
    if(n%2){
        rep(i,n){
            if(i==0){
                if(a[i]!=0) flag=0;
            }else{
                if(a[i]!=(i+1)/2*2) flag=0;
            }
        }
    }else{
        rep(i,n){
            if(a[i]!=(i+2)/2*2-1) flag=0;
        }
    }
    if(flag) cout<<modpow(2,n/2)<<endl;
    else cout<<0<<endl;
    return 0;
}