#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int delta=0;
  if((min(b, d) - max(a, c)) > 0)
  delta = min(b, d) - max(a, c);
  
  cout << delta << endl;
 return 0;
}