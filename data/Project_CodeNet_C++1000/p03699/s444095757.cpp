#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
#define wzh(x) cerr<<#x<<'='<<x<<endl;
int n,a[N];
int dp[N];
int main() {
  ios::sync_with_stdio(false);
  cin>>n;dp[0]=1;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    for(int j=10000;j>=a[i];j--){
      dp[j]|=dp[j-a[i]];
    }
  }
  int ans=0;
  for(int i=1;i<=10000;i++){
    if(i%10 && dp[i])ans=i;
  }
  cout<<ans<<'\n';
  return 0;
}