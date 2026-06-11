#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  int a,b;
  cin >> a >> b;
  int ans = a+b;
  if(ans < 24) cout << ans << endl;
  else cout << ans-24 << endl;
}