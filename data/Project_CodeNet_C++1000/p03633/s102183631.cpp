#include<bits/stdc++.h>
using namespace std;
using ll=long long;
//GCD,LCM
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
    int n;
    cin>>n;
    vector<ll> t;
    for(int i=0;i<n;++i){
        ll time;cin>>time;
        t.push_back(time);
    }
    ll ans=1;
    for(int i=0;i<n;++i){
        ans=lcm(ans,t[i]);
    }
    cout<<ans<<endl;
    return 0;
}