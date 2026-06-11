#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){

  char s[100006];

  scanf("%s", s);

  int i;
  int n;
  int ans = 0;
  n = strlen(s);
  for(i = 0;i < n - 1;i++){
    if(s[i] == 'W' && s[i + 1] == 'B' || s[i] == 'B' && s[i + 1] == 'W') ans++;
  }

  printf("%d\n", ans);

  return 0;
}
