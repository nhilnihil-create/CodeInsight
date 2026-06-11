#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  ll a, b, x;
  cin >> a >> b >> x;
  b = b / x;
  if(a != 0) a = (a - 1) / x;
  else a--;
  cout << b - a << endl;

  return 0;
}
