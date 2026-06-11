#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;

int N,K;
int dp[5000];
int a[5000];

bool solve(int pass){
  if(a[pass]>=K)return false;
  REP(i,K)dp[i]=0;
  dp[0]=1;
  REP(i,N){
    if(i==pass)continue;
    for(int j=K-1;j>=0;j--){
      if(dp[j]==0)continue;
      if(j+a[i]>K)continue;
      dp[j+a[i]]=1;
    }
  }
  FOR(i,K-a[pass],K)if(dp[i]==1)return false;
  return true;

}
int main(){
  cin>>N>>K;
  REP(i,N)cin>>a[i];
  sort(a,a+N);
  if(!solve(0)){
    cout<<0<<endl;
    return 0;
  }
  int l=0;
  int r=N;
  while(r-l>1){
    if(solve((l+r)/2))l=(l+r)/2;
    else r=(l+r)/2;
  }
  // int ans=0;
  // REP(i,N){
  //   if(solve(i))ans++;
  // }
  cout<<r<<endl;
  return 0;
}
