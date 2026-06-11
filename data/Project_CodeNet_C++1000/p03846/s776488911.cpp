#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int a[100006];
int cnt[100006];

int main(){
  int n;
  int i;
  ll ans = 1;

  scanf("%d", &n);

  for(i = 0;i <= n;i++) cnt[i] = 0;

  for(i = 0;i < n;i++){
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }

  if(n % 2 == 0){
    for(i = 1;i < n;i += 2){
      if(cnt[i] != 2){
        printf("0\n");
        return 0;
      }
    }

    n = n/2;
    for(i = 0;i < n;i++) ans = ans*2 % MODSIZE;
    printf("%lld\n", ans);
  }

  else {
    if(cnt[0] != 1){
      printf("0\n");
      return 0;
    }

    for(i = 2;i < n;i += 2){
      if(cnt[i] != 2){
        printf("0\n");
        return 0;
      }
    }

    n = n/2;
    for(i = 0;i < n;i++) ans = ans*2 % MODSIZE;
    printf("%lld\n", ans);
  }

  return 0;
}
