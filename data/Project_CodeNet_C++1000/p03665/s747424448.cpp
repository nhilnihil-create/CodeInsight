#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=(1<<29);
int main(){
  ll n,p,i,j,dp[55][3],a[55];
  scanf("%lld %lld\n",&n,&p);
  for(i=1;i<=n;i++){
    scanf("%lld ",&a[i]);
    a[i]=a[i]%2;
  }
  for(i=0;i<=n;i++){
    for(j=0;j<=1;j++){
      dp[i][j]=0;
    }
  }
  dp[0][0]=1;
  for(i=1;i<=n;i++){
    if(a[i]==0){
      dp[i][0]=2*dp[i-1][0];
      dp[i][1]=2*dp[i-1][1];
    }
    else{
      dp[i][0]=dp[i-1][0]+dp[i-1][1];
      dp[i][1]=dp[i-1][1]+dp[i-1][0];
    }
  }
  printf("%lld\n",dp[n][p]);
  return 0;
}