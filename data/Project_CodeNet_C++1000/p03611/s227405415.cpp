#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n;
  cin >> n;
  int a[n];
  M mp;
  rep(i, n) {
    cin >> a[i];
    mp[a[i]]++;
    mp[a[i] - 1]++;
    mp[a[i] + 1]++;
  }
  int ans = 0;
  rep(i, 1000005) ans = max(ans, mp[i]);
  cout << ans << endl;
    
    

  return 0;
}