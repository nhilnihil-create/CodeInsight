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
  int score[120];
  int sum = 0;
  rep(i,n) {cin >> score[i]; sum += score[i];}
  if (sum % 10 != 0) {
    cout << sum << endl;
    return 0;
  }
  
  int ans = 0;
  rep(i,n) {
    if (score[i] % 10 == 0) continue;
    int now = sum - score[i];
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}