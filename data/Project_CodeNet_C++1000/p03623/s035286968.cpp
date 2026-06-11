#include <bits/stdc++.h>
using namespace std;

int main () {
  int x,a,b;
  cin >> x >> a >> b;

  int xa,xb;
  if (x>a) xa=x-a;
  else xa=a-x;
  if (x>b) xb=x-b;
  else xb=b-x;

  char ans;
  if (min(xa,xb)==xa) ans='A';
  else ans='B';

  cout << ans << endl;
  
  return 0;
}
