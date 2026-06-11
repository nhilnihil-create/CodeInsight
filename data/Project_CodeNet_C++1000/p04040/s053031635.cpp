#include<bits/stdc++.h>
#define md 1000000007
#define MAX 200000
using namespace std;
typedef long long ll;

ll f1[MAX], f2[MAX];
void Setc(int n){
  f1[1] = 1;
  for(int i = 1; i <= n; i++) f1[i+1] = f1[i]*(i+1)%md;
  ll y = f1[n+1]; f2[n+1] = 1;
  for(int i = md-2; i; i/=2){
    if(i&1) f2[n+1] = f2[n+1]*y%md;
    y = y*y%md;
  }
  for(int i = n; i >= 0; i--) f2[i] = f2[i+1]*(i+1)%md;
}
ll comb(int n, int m){ return f1[n]*f2[n-m]%md*f2[m]%md;}	

int main(){
  int h, w, a, b;
  ll ans = 0;
  scanf("%d%d%d%d", &h, &w, &a, &b);
  Setc(h+w);
  ans += comb(h+w-2, w-1);
  for(; a > 0 && b > 0; a--, b--){
    ans = (ans + md - comb(h-a+b-1, b-1)*comb(w+a-1-b, w-b)%md)%md;
  }
  printf("%lld\n", ans);
}