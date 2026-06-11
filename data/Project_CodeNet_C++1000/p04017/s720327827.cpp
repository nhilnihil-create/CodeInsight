#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, l, q;
int x[N];
int dp[N][21];
ll sum[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x[i]);
  }
  memset(sum, 0, sizeof(sum));
  for (int i = 2; i <= n; ++i) {
    sum[i] = sum[i-1]+x[i]-x[i-1];
  }
  memset(dp, -1, sizeof(dp));
  scanf("%d", &l);
  for (int i = 1; i < n; ++i) {
    int y = i;
    int z = n;
    while(y<z) {
      int mid=(y+z+1)/2;
      if (sum[mid]-sum[i]>l) {
        z = mid-1;
      } else {
        y = mid;
      }
    }
    dp[i][0] = y;
  }
//  cout<<dp[5][0]<<" "<<dp[7][0]<<endl;
  for (int j = 1; j <= 20; ++j) {
    for (int i = 1; i <= n; ++i) {
      if (dp[i][j-1] >= 0 && dp[dp[i][j-1]][j-1] >= 0) {
        dp[i][j] = dp[dp[i][j-1]][j-1];
      }
    }
  }
//  cout<<"x="<<dp[5][3]<<endl;
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a > b) swap(a, b);
    int res=0;
    int cur=a;
    for (int j = 20; j >= 0; --j) {
      if (dp[cur][j] >= 0 && dp[cur][j] <= b) {
     //   if (a==5 && b==8) cout<<"j="<<cur<<" "<<j<<" "<<dp[cur][j]<<endl;
        res += 1<<j;
        cur = dp[cur][j];
      }
    }
    if (cur < b) res++;
    cout<<res<<endl;
  }
  return 0;
}
