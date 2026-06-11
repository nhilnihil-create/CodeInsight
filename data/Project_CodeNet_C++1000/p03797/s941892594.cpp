#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  ll n,m;
  ll ans = 0;

  scanf("%lld %lld", &n, &m);

  if(2*n > m){
    printf("%lld\n", m/2);
  }

  else {
    m -= 2*n;
    ans += n + m/4;
    printf("%lld\n", ans);
  }

  return 0;
}
