#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  int n;

  scanf("%d", &n);

  ll ans = 1;
  int cnt[1005];

  int i,j;

  for(i = 0;i <= 1000;i++) cnt[i] = 0;

  int a;

  for(i = 2;i <= n;i++){
    a = i;
    for(j = 2;j*j <= i;j++){
      while(a % j == 0){
        cnt[j]++;
        a /= j;
      }
    }
    if(a != 1) cnt[a]++;
  }

  for(i = 2;i <= n;i++) ans = ans*(cnt[i] + 1) % MODSIZE;

  printf("%lld\n", ans);

  return 0;
}