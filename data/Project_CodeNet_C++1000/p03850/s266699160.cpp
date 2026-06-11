//Link : https://atcoder.jp/contests/arc066/tasks/arc066_c

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200005

int A[N],op[N];
ll dp[N][4];

int getValue(int o,int bit,int v) {
  bit^=o;
  if(bit&1) {
    return -v;
  }
  return v;
}
ll solveDp(int ind,int bit,int n) {
  if(ind>n) {
    return 0;
  }
  ll &ret = dp[ind][bit];
  if( ret!=-1) {
    return ret;
  }
  for(int i=0;i<bit;++i) {
    ret = max(ret, solveDp(ind,i,n));
  }

  ret = max(ret,solveDp(ind+1,bit,n) + getValue(op[ind-1],bit,A[ind]));
  if(op[ind-1]) {
    if(bit!=3) {
      ret = max(ret,getValue(op[ind-1],bit,A[ind]) + solveDp(ind+1,bit+1,n));
    }
  }

  return ret;
}
void solve() {
  int n;scanf("%d ",&n);
  for(int i=1;i<=n;++i) {
    scanf("%d ", &A[i]);
    char c;
    if(i!=n) {
      scanf(" %c ", &c);
      if(c=='-') {
        op[i] = 1;
      }
    }
  }
  memset(dp,-1,sizeof(dp));
  printf("%lld\n", solveDp(1,0,n));
}
int main() {
    //freopen("input.txt","r",stdin);
    solve();
    return 0;
}
