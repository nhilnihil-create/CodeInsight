#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int u = max(a, c);
  int l = min(b, d);

  if (l - u < 0) cout << 0 << endl;
  else cout << l - u << endl;
  return 0;
}