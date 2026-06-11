#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if(a<c && c<b && b<d) cout << b-c << endl;
  else if(a<=c && d<=b ) cout << d-c << endl;
  else if(c<a && a<d && d<b ) cout << d-a << endl;
  else if(c<=a && d>=b) cout << b-a << endl;
  else cout << 0 << endl;
}
