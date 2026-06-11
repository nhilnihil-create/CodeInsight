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

  scanf("%d", &n);

  for(i = 0;i <= 100000;i++) cnt[i] = 0;
  for(i = 0;i < n;i++){
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }

  ll ans = 0;
  ll t = 0;
  for(i = 1;i <= 100000;i++){
    if(cnt[i] % 2 == 1) ans++;

    else if(cnt[i] >= 2){
      t++;
    }
  }

  if(t % 2 == 0) ans += t;

  else ans += t - 1;

  printf("%lld\n", ans);

  return 0;
}