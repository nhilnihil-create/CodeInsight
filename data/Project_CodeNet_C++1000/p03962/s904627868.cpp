#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
  int a,b,c;
  cin >> a >> b >> c;

  if(a == b && b == c)
  {cout << 1 << endl;}

  else if(a == b)
  {cout << 2 << endl;}

  else if(b == c)
  {cout << 2 << endl;}

  else if(a == c)
  {cout << 2 << endl;}

  else{cout << 3 << endl;}
}