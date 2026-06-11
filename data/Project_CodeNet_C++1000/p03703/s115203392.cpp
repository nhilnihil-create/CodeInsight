#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

class BIT{//1-indexed
public:

  vector<ll> bit;
  BIT(){}
  BIT(int size){
    bit.resize(size,0);
  }

  ll sum(int i){
    ll s=0;
    while(i>0){
      s+=bit[i];
      i-=i&(-i);
    }
    return s;
  }

  void add(int i,ll x){//i!=0
    while(i<bit.size()){
      bit[i]+=x;
      i+=i&(-i);
    }
  }
};

int N;
ll K;
vector<ll> A;

int main(){
  cin>>N>>K;
  A.resize(N);
  rep(i,N) cin>>A[i];

  rep(i,N) A[i]-=K;

  vector<ll> sum(N+1,0);
  vector<ll> v;
  v.push_back(0);
  for(int i=0;i<N;i++){
      sum[i+1]=sum[i]+A[i];
      v.push_back(sum[i+1]);
  }
  sort(v.begin(),v.end());

  map<ll,int> mp;
  int cnt=1;
  for(int i=0;i<v.size();i++){
      if(mp[v[i]]==0) mp[v[i]]=cnt++;
  }

  BIT bit(cnt+1);
  bit.add(mp[sum[0]],1);

  ll ans=0;
  for(int i=1;i<=N;i++){
      ll res=bit.sum(mp[sum[i]]);
      ans+=res;
      bit.add(mp[sum[i]],1);
  }
  cout<<ans<<endl;

  return 0;
}
