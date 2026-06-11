#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<int,int> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
set<string> c;
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
map<ll,ll> bag,keep;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n,W;cin>>n>>W;
bag[0]=0;
vector<ll> w(n),v(n);
for(int i=0;i<n;i++)cin>>w[i]>>v[i];
for(int i=0;i<n;i++){
    for(auto p: bag){
    if(p.fi+w[i]>W)continue;
   keep[p.fi+w[i]]=max(bag[p.fi+w[i]],p.se+v[i]);
  }
 for(auto p: keep){
   bag[p.fi]=p.se;
 }
 keep.clear();
}
ll ans=0;
for(auto p: bag){
  //cout<<p.fi<<" "<<p.se<<endl;
  chmax(ans,p.se);
}
cout<<ans<<endl;
}
