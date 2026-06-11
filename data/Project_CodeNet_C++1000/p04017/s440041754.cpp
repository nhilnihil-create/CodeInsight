#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <queue>
#include <string.h>
#include <set>
using namespace std;

#define N 100005
#define M 20
#define mod 1000000007

int x[N],dp[N][M];
int jumpCity(int stCity,int day) {
  int curCity = stCity;
  for(int i=0;i<M;++i) {
    if(day&(1<<i)) {
      curCity = dp[curCity][i];
    }
  }
  return curCity;
}
void solve() {
  int n;scanf("%d ", &n);
  for(int i=1;i<=n;++i) {
    scanf("%d ", &x[i]);
  }
  int L;scanf("%d ", &L);
  for(int i=0;i<M;++i) {
    dp[n+1][i] = n+1;
    dp[n][i] =n+1;
  }
  int lastCity = n;
  int dist = x[n] - x[n-1];
  for(int i=n-1;i>=1;--i) {
    while(dist>L) {
      dist -= x[lastCity] - x[lastCity-1];
      --lastCity;
    }
    dp[i][0] = lastCity;
    for(int j=1;j<M;++j) {
      dp[i][j] = dp[dp[i][j-1]][j-1];
    }
    dist += x[i] - x[i-1];
  }
  int q;scanf("%d ", &q);
  while(q--) {
    int a,b;scanf("%d %d ", &a,&b);
    if(a>b) {
      swap(a,b);
    }
    int l = 1,r = n,mid;
    while(l<r) {
      mid = (l+r)/2;
      int arrived = jumpCity(a,mid);
      if(b<=arrived) {
        r = mid;
      } else {
        l = mid+1;
      }
    }
    printf("%d\n", l);
  }
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
