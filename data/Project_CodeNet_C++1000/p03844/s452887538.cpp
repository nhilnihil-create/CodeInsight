#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  int a,b;
  char op[2];

  scanf("%d %s %d", &a, op, &b);

  if(op[0] == '+') printf("%d", a + b);

  else printf("%d", a - b);

  return 0;
}
