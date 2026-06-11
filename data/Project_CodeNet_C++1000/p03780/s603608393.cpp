#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) std::memset(arg,n,sizeof(arg))
using std::cin;
typedef long long ll;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
const int INF=1e+9;
const ll INFLL=1e+17;
int N,K;
int a[5010],dp[5010][5010];
bool C(int i){
  if(a[i]>=K) return true;
  
  fill(dp,0);
  rep1(j,N){
    rep(k,K){
      if(j-1==i||k-a[j-1]<0) dp[j][k]=dp[j-1][k];
      else dp[j][k]=std::max(dp[j-1][k],dp[j-1][k-a[j-1]]+a[j-1]);
    }
  }
  if(dp[N][K-1]>=K-a[i]) return true;
  else return false;
}
int bina(int l,int r){
  int lb=l-1,ub=r+1;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(C(mid)) ub=mid;
    else lb=mid;
  }
  return ub;
}
int solve(){
  std::sort(a,a+N);
  return bina(0,N-1);
}
int main(){
  cin>>N>>K;
  rep(i,N) cin>>a[i];
  prin(solve());
  return 0;
}
