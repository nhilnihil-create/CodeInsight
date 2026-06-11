#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int x,a,b;
  cin >> x >> a >> b;
  int n,m;
  n = abs(x-a);
  m = abs(x-b);
  if(n < m) puts("A");
  else puts("B");
  return 0;
}
