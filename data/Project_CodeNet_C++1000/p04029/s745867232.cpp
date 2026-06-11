#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  int n;

  int i;
  int sum = 0;

  scanf("%d", &n);

  for(i = 1;i <= n;i++) sum += i;

  printf("%d\n", sum);
  return 0;
}