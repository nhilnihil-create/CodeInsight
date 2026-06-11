#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
  int n,T;
  cin >> n >> T;
  vector<int> t(n);
  ll end = 0;
  ll ans = 0;
  rep(i, n)
  {
    cin >> t[i];
    if(end < t[i]){
      end = T + t[i];
      ans += T;
    }else{
      ans += T + t[i] - end;
      end = t[i] + T;
    }
  }
  cout << ans << endl;
}