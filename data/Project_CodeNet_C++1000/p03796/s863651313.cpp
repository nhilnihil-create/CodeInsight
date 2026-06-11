#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  ll ans = 1;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    ans = i * (ans % 1000000007);
  }
  cout << ans % 1000000007 << endl;
  

  return 0;
}
