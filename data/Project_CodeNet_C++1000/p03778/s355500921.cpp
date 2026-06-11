#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){

  int w,a,b;

  scanf("%d %d %d", &w, &a, &b);

  if(abs(a - b) <= w) printf("0\n");
  
  else printf("%d\n", abs(a - b) - w);

  return 0;
}