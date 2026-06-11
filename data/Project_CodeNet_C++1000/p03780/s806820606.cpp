#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <algorithm>
#define llint long long
#define mod 1000000007
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n, k;
llint a[5005];
bool dp[5005][5005];

bool check(llint x)
{
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= k; j++){
      dp[i][j] = false;
    }
  }
  dp[0][0] = true;

  for(int i = 0; i < n; i++){
    for(int j = 0; j <= k; j++){
      if(!dp[i][j]) continue;
      dp[i+1][j] = true;
      if(i+1 != x && j+a[i+1] <= k) dp[i+1][j+a[i+1]] = true;
    }
  }

  for(int j = max(0LL, k-a[x]); j < k; j++){
    if(dp[n][j]) return true;
  }
  return false;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> a[i];
  sort(a+1, a+n+1);

  llint ub = n+1, lb = 0, mid;
  while(ub-lb>1){
    mid = (ub+lb)/2;
    if(check(mid)) ub = mid;
    else lb = mid;
  }
  cout << ub-1 << endl;

  return 0;
}
