#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a > d) cout << 0 << endl;
  else if (c > b) cout << 0 << endl;
  
  else if ((a <= c) && (b >= d)) cout << d - c << endl;
  else if ((a >= c) && (b <= d)) cout << b - a << endl;

  else if ((a <= c) && (b <= d)) cout << b - c << endl;
  else if ((a >= c) && (b >= d)) cout << d - a << endl;
  return 0;
}