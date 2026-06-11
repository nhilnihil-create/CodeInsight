#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  ll x;
  ll t;
  scanf("%lld", &x);
  t = x % 11;

  ll ans;
  ans = x/11;

  if(t == 0){
    ans = 2*ans;
  }

  else if(t <= 6) ans = ans*2 + 1;

  else ans = ans*2 + 2;

  printf("%lld\n", ans);

  return 0;
}