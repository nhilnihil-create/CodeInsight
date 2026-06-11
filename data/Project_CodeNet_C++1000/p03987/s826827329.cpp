#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define all(v) (v).begin(),v.end()
#define fi first
#define se second
set<string> c;
map<ll,ll> mp;
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
int main(){
int n;
cin>>n;
vector<ll> a(n),ind(n);
for(int i=0;i<n;i++){cin>>a[i];--a[i];}
for(int i=0;i<n;i++)ind[a[i]]=i;
set<ll> s;
ll ans=0;
for(int x=0;x<n;x++){
    ll i=ind[x];
    ll c=0;
    s.insert(i);
    ll l=-1,r=n;
    auto ite=s.find(i);
    if(ite!=s.begin()){ite--;l=*ite;}
    ite=s.find(i);
    ite++;
    if(ite!=s.end())r=*ite;
    c=(i-l)*(r-i);
    ans+=(x+1)*c;
}
cout<<ans<<endl;
}



