#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int w, a, b;
  cin >> w >> a >> b;
  int ans = max(a, b) - (w + min(a, b));
  if(ans < 0) ans =0;
  cout << ans << endl;
  

  return 0;
}
