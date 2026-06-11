#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  char a[14],b[14],c[14];
  int na,nb,nc;
  int cnt[27] = {0};

  scanf("%s %s %s", a, b, c);
  na = strlen(a);
  nb = strlen(b);
  nc = strlen(c);

  if(a[na - 1] == b[0] && b[nb - 1] == c[0]) printf("YES\n");

  else printf("NO\n");

  return 0;
}
