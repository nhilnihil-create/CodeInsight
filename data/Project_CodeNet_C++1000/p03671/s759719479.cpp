#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  if (a>c && a>b) cout << b+c << endl;
  else if (b>c && b>a) cout << a+c << endl;
  else if (a>c) cout << b+c << endl;
  else if (b>c) cout << a+c << endl;
  else cout << a+b << endl;
}