#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){

  int a,b;

  scanf("%d %d", &a, &b);

  if(a + b < 24) printf("%d\n", a + b);

  else printf("%d\n", a + b - 24);
  
  return 0;
}