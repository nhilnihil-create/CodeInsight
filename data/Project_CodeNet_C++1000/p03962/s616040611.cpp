#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int res = 3;
  if (a == b)
    res--;
  else if (a == c)
    res--;
  if (b == c)
    res--;
  cout << res << endl;
  
  return 0;
  
}