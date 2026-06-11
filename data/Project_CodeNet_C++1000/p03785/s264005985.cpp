#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30; 
int main() {
  int n,c;
  ll k;
  cin >> n >> c >> k;
  vector<ll> t(n);
  rep(i,n) cin >> t[i];
  sort(t.begin(), t.end());
  int passenger = 1; ll dep = t[0]+k;
  int ans = 0;
  int i = 0;
  while (i < n)
  {
    //cout << dep << endl;
    while (true)
    {
      if (passenger > c || dep < t[i]) {
        ans++;
        passenger = 1;
        dep = t[i] + k; break;
      }
      passenger++; i++;
    }
    
  }
  
  cout << ans << endl;
  
  
  
  return 0;
}