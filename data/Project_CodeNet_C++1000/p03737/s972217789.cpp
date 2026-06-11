#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
 
int main()
{
  string a,b,c;
  cin >> a>> b>> c;
  a[0] = a[0] - 32;
  b[0] -= 32;
  c[0] -= 32;
  cout << a[0] << b[0] << c[0] << endl;
  return 0;
}