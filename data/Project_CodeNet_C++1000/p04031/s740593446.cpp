#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  int n;
  int ave1,ave2;
  int sum = 0;
  int a[105];
  int i;

  scanf("%d", &n);
  for(i = 0;i < n;i++){
    scanf("%d", &a[i]);
    sum += a[i];
  }

  ave1 = sum/n;
  ave2 = sum/n + 1;

  ll ans1 = 0;
  ll ans2 = 0;

  for(i = 0;i < n;i++){
    ans1 += (ave1 - a[i])*(ave1 - a[i]);
    ans2 += (ave2 - a[i])*(ave2 - a[i]);
  }

  printf("%lld\n", min(ans1,ans2));

  return 0;
}