#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll k;
cin>>k;
if(k>1&&k<=50){
    vector<int> a(k,k);
    cout<<k<<endl;
    for(int i=0;i<k;i++)cout<<a[i]<<" ";
    cout<<endl;
}
else if((k==1||k==0)){
    if(k==0){
        cout<<2<<endl;
        cout<<1<<" "<<1<<endl;
    }
    else {
        cout<<2<<endl;
        cout<<0<<" "<<2<<endl;
    }
}
else{
    ll t=k%50;
    cout<<50<<endl;
    vector<ll> a(50,k/50+50);
    for(int i=t;i<50;i++)a[i]-=t+1;
    for(int i=0;i<50;i++)cout<<a[i]<<" ";
    cout<<endl;
    
}
}