#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main()
{
  string a,b,c;
  cin >> a >> b >> c;
  char dif = 'A'-'a';
  printf("%c%c%c\n", a[0]+dif, b[0]+dif, c[0]+dif);
}