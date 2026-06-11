#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<int,int> P;
typedef tuple<ll,int,int> T;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
set<string> c;
const ll mod=1000000007;
const ll mod2=998244353;
const ll inf=100000000000000000;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
vector<int> dy={-1,0,1,0},dx={0,-1,0,1};
map<ll,int> b;
int main(){
int n;
cin>>n;
vector<ll> a(3*n);
ll lsum=0,rsum=0;
for(int i=0;i<3*n;i++){
    cin>>a[i];
    if(i<n)lsum+=a[i];
    else if(2*n<=i) rsum+=a[i];
}
priority_queue<ll> pr;
priority_queue<ll,vector<ll>,greater<ll>> pl;
for(int i=0;i<n;i++)pl.push(a[i]);
for(int i=2*n;i<3*n;i++)pr.push(a[i]);
vector<ll> l(n+1),r(n+1);
l[0]=lsum;r[n]=rsum;
for(int i=n;i<2*n;i++){
    pl.push(a[i]);
    ll tmp=pl.top();
    pl.pop();
    lsum+=(a[i]-tmp);
    l[i-n+1]=lsum;
}
for(int i=2*n-1;i>=n;i--){
    pr.push(a[i]);
    ll tmp=pr.top();
    pr.pop();
    rsum+=(a[i]-tmp);
    r[i-n]=rsum;
}
ll ans=-inf;
for(int i=0;i<=n;i++){
    ans=max(l[i]-r[i],ans);
}
cout<<ans<<endl;
}