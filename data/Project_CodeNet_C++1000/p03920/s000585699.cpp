#include <bits/stdc++.h>

typedef long long ll;
#define int ll

using namespace std;

signed main(){
  int N;
  int n=1;

  scanf("%lld", &N);
  
  while(0.5*n*(n+1) <= N) n++;
  ll gap = n*(n+1)*0.5-N;
  
  for(ll i = 1 ; i <= n ; i++){
    if(i == gap) continue;
    printf("%lld\n", i);
  }

}
