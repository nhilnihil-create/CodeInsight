#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,m,ans=0;
  cin >> n >> m;
  if(n*2<=m) ans+=n,m-=n*2;
  else ans+=m/2,m=0;
  ans+=m/4;
  cout << ans << endl;
}