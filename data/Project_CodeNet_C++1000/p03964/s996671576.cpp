#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

ll ten(ll a,ll b){
  ll res;

  if(a % b == 0) res = a/b;

  else res = a/b + 1;

  return res;
}

int main(){

  int n;
  int a[1007],b[1007];
  int i;
  ll A,B;
  ll t;

  scanf("%d", &n);
  for(i = 0;i < n;i++){
    scanf("%d %d", &a[i], &b[i]);
  }

  A = 1; B = 1;

  for(i = 0;i < n;i++){
    t = max(ten(A,a[i]),ten(B,b[i]));
    A = t*a[i];
    B = t*b[i];
  }

  printf("%lld\n", A + B);
  return 0;
}