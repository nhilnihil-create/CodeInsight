#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main () {
  int x,a,b;cin>>x>>a>>b;
  if(b<=a)cout << "delicious" << endl;
  else if(b<=a+x)cout << "safe" << endl;
  else cout << "dangerous" << endl;
}