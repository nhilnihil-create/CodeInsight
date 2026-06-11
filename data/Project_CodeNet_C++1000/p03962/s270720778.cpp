#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  int a,b,c;
  int cnt[106];
  int i;

  for(i = 0;i < 105;i++) cnt[i] = 0;

  scanf("%d %d %d", &a, &b, &c);
  cnt[a]++;
  cnt[b]++;
  cnt[c]++;

  int ans = 0;
  for(i = 0;i <= 100;i++) if(cnt[i] != 0) ans++;

  printf("%d\n", ans);
  return 0;
}