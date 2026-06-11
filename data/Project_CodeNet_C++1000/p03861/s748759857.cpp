#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main() {
  long long a=0, b=0, x=0, ans=0;
  long long one = 0;
  cin >> a >> b >> x;
  if (a-1 < 0 ) ans = (b/x + 1);
  else ans = (b/x - (a-1) / x);
  cout << ans << endl;
}