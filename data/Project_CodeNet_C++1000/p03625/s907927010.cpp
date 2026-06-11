#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    ll n,a;
    cin>>n;
    map<ll,ll> mp;
    rep(i,n){
        cin>>a;
        mp[-a]++;
    }
    ll h=0,w=0;
    for(auto x:mp){
        if(x.second>=4){
            if(h==0){
                h=w=-x.first;
                break;
            }else{
                w=-x.first;
                break;
            }
        }else if(x.second>=2){
            if(h==0) h=-x.first;
            else{
                w=-x.first;
                break;
            }
        }
    }
    cout<<h*w<<endl;
    return 0;
}