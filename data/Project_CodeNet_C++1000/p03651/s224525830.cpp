#include <iostream>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std; typedef long long ll; const int INF=1e9; typedef pair<ll,ll> P;

int gcd(int a, int b) {
  if (b==0) return a;
  else return gcd(b, a%b);
}

int main() {
  int n,k; cin>>n>>k;
  int a[n]; int mx=-1e9;
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) mx=max(mx,a[i]);
  
  if (mx < k) return puts("IMPOSSIBLE")*0;

  int g=a[0];
  for(int i=1;i<n;i++) g=gcd(g,a[i]);
  if (k%g) return puts("IMPOSSIBLE")*0;
  else return puts("POSSIBLE")*0;
}