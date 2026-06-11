#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  string a,b,c;
  cin >> a >> b >> c;
  char q,w,e;
  q = a[0]; w = b[0]; e = c[0];
  q -= 32; w -= 32; e -= 32;
  cout << q << w << e;
}