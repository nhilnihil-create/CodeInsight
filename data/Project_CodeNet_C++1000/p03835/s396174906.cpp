#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int k, s;
  cin >> k >> s;
  int ans = 0;
  rep(i, k + 1){
    rep(j, k + 1){
      int z = s - i - j;
      if(0 <= z && z <= k) ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
