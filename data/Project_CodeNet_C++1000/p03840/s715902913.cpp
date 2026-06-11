#include <bits/stdc++.h>
using namespace std;

int main() {
  long a,b,c,d,e,f,g;
  cin >> a >> b >> c >> d >> e >> f >> g;
  long suma=0,sumb;
  if(a>0 && d>0 && e>0)suma=((a-1)/2)*2+b+((d-1)/2)*2+((e-1)/2)*2+3;
  sumb=(a/2)*2+b+(d/2)*2+(e/2)*2;
  cout << max(suma,sumb);
}
