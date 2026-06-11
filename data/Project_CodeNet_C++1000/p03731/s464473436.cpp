#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int main(){
    ll n,t;
    cin>>n>>t;
    vector<ll> ti(n);
    rep(i,n) cin>>ti[i];
    ll sum=0;
    rep(i,n-1) sum+=min(t,ti[i+1]-ti[i]);
    sum+=t;
    cout<<sum<<endl;
    return 0;
}