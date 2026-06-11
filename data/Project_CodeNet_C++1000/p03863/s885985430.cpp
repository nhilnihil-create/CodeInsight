#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  char s[100006];
  bool f = false;
  bool same = false;

  scanf("%s", s);

  int n;
  n = strlen(s);

  if(n % 2 == 0) f = true;
  if(s[0] == s[n - 1]) same = true;

  if(f^same) printf("Second\n");

  else printf("First\n");

  return 0;
}
