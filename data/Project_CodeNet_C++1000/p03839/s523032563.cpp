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
ll N,K;
ll a[100010];
int main(){
  cin>>N>>K;
  rep(i,N) cin>>a[i];
  ll cump[100010];
  cump[0]=0;
  rep1(i,N){
    if(a[i-1]>0) cump[i]=cump[i-1]+a[i-1];
    else cump[i]=cump[i-1];
  }
  ll sum[100010];
  sum[0]=0;
  rep1(i,N){
    sum[i]=sum[i-1]+a[i-1];
  }
  ll res=0;
  rep(i,N-K+1){
    ll s=sum[i+K]-sum[i];
    ll t=cump[i]+cump[N]-cump[i+K];
    if(s<0) res=std::max(res,t);
    else res=std::max(res,s+t);
  }
  prin(res);
  return 0;
}
