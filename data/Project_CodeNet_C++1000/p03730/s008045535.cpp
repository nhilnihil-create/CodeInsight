#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  ll x = 0;
  string ans = "NO";
  for(int i = 1; i <= 1000000; i++) {
    x += a;
    if(x % b == c) ans = "YES";
  }
  cout << ans << endl;
  return 0;
}