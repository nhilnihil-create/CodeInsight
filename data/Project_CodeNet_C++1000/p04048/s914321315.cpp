#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<int,int> P;
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
ll dfs(ll a,ll b){
    ll res=0;
    return res+=(a%b?a/b*2*b+dfs(b,a%b):a/b*2*b-b);
}
int main(){
   ll n,x;cin>>n>>x;
   ll ans=0;
   ll tmp=n-x;
   if(tmp<x)swap(x,tmp);
   ans=dfs(tmp,x)+n;
   cout<<ans<<endl;
}
