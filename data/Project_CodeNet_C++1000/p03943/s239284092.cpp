#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  int a,b,c;
  int mx;
  int t;

  scanf("%d %d %d", &a, &b, &c);
  mx = max(max(a,b),c);
  t = a + b + c - mx;

  if(mx == t) printf("Yes\n");

  else printf("No\n");

  return 0;
}
