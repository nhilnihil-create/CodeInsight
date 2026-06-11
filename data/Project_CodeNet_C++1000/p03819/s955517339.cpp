#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod;
#define mul(a,b) a=a*b%mod;
#define N 200010
namespace bit{
  ll dat[N];
  void init(){
      for(int i=0;i<N;i++){
          dat[i]=0;
      }
  }
  void add(ll i,ll x){
      for(;i<N;i+=i&-i){
          dat[i]+=x;
      }
  }
  ll sum(ll i){
      ll res=0;
      for(;i;i-=i&-i){
          res+=dat[i];
      }
      return res;
  }
};
ll n,m;
struct qry{
    ll l,r,id;
    bool operator<(const qry&key)const{
        if(this->r==key.r)return this->id<key.id;
        return this->r<key.r;
    }
};
ll ans[N];
int main(){
  cin>>n>>m;
  vector<qry> v;
  for(int i=0;i<n;i++){
      qry p;
      cin>>p.l>>p.r;
      p.id=0;
      v.push_back(p);
  }
  for(int d=1;d<=m;d++){
      ans[d]=n;
      for(int i=0;i<=m;i+=d){
          qry p;
          p.l=i,p.r=i+d-1;
          p.id=d;
          v.push_back(p);
      }
  }
  sort(v.begin(),v.end());
  bit::init();
  for(auto p:v){
      if(p.id==0){
          bit::add(p.l,+1);
      }
      else{
          ans[p.id]-=(bit::sum(p.r)-bit::sum(p.l));
      }
  }
  for(int d=1;d<=m;d++)cout<<ans[d]<<endl;
  return 0;
}

