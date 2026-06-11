#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) std::memset(arg,n,sizeof(arg))
#define mp std::make_pair
#define pb push_back
using std::cin;
typedef long long ll;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::set<int> si;
typedef std::string str;
const int INF=1e+9;
const ll INFLL=1e+17;
const ll MOD=1e+9+7;
ll N,A,B;
ll h[100010];
bool C(ll x){
  //条件を入れる
  ll y=A-B,z=B*x;
  ll cnt=0;
  rep(i,N){
    if(h[i]-z>0) cnt+=(h[i]-z-1)/y+1;
  }
  return cnt<=x;
}
ll upper(ll l,ll r){//条件を満たす中で最小のものを返す
  ll lb=l-1,ub=r+1;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    if(C(mid)) ub=mid;
    else lb=mid;
  }
  return ub;
}
int main(){
  cin>>N>>A>>B;
  rep(i,N) cin>>h[i];
  ll max=0;
  rep(i,N) max=std::max(max,h[i]);
  prin(upper(1,(max-1)/B+1));
  return 0;
}
