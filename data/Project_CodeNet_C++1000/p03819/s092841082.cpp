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
#define N 300010
#define M 100010
namespace bit{
    ll dat[N];
    void init(){
        for(int i=0;i<N;i++)dat[i]=0;
    }
    void add(ll i){
        for(;i<N;i+=i&-i){
            dat[i]++;
        }
    }
    ll sum(ll i){
        ll res=0;
        for(;i>0;i-=i&-i){
            res+=dat[i];
        }
        return res;
    }
}
vector<ll> v[2*M];
ll n,m;
ll ans[2*M];
int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
      ll l,r; cin>>l>>r;
      v[r].push_back(l);
  }
  bit::init();
  for(int i=1;i<=2*m;i++){
      vector<ll> di;
      for(ll j=1;j*j<=i;j++){
          if(i%j==0){
              di.push_back(j);
              if(j*j!=i){
                  di.push_back(i/j);
              }
          }
      }
      for(auto d:di){
          ans[d]+=bit::sum(i-1)-bit::sum(i-d);
          //cout<<"---"<<d<<" "<<ans[d]<<endl;
      }
      for(auto l:v[i]){
          bit::add(l);
      }
      //for(int j=1;j<=m;j++)cout<<bit::sum(j)<<" "; cout<<endl;
  }
  for(int i=1;i<=m;i++){
      cout<<n-ans[i]<<endl;
  }
  return 0;
}
