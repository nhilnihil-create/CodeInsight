#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){

  int x,y,n,k;

  cin >> n >> k >> x >> y;

  if(n <= k) printf("%d\n", n*x);

  else {
    printf("%d\n", k*x + (n - k)*y);
  }
  
  return 0;
}
