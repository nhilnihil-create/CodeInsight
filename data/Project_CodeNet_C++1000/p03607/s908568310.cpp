#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  int ans = 0, ptr = 0;
  while (ptr < n)
  {
    int cc = a[ptr], cnt = 0;
    while (ptr < n && a[ptr] == cc)
    {
      ptr++; cnt++;
    }
    ans += (cnt % 2);
  }
  cout << ans << endl;
  return 0;
}