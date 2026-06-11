#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
  string A,x,B;
  cin >> A >> x >> B;
  int ans=0;
  if(x=="+")
  {ans = stoi(A) + stoi(B);}
  else{ans = stoi(A) - stoi(B);}
  cout << ans << endl;
}