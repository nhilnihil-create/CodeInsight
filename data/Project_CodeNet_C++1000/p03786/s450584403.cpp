#include <bits/stdc++.h>
using namespace std;

// using ll = long long;
#define int long long

#define LOG(variable) cout << #variable":\t" << (variable) << endl
#define LOGCON(i, container) for(int (i) = 0; (i) < (container).size(); ++(i)) cout << (i) << ":\t" << (container)[(i)] << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, r, n) for (int i = (r); i < (n); ++i)
#define REPR(i, n) for(int i = (n); i >= 0; --i) // from n to 0
#define REPRS(i, r, n) for(int i = (n); i >= (r); --i) // from n to r
#define REPOBJ(itr, obj) for(auto itr = (obj).begin(); itr != (obj).end() ; ++itr)
#define REPROBJ(itr, obj) for(auto itr = (obj).rbegin(), e = (obj).rend(); itr != e; ++itr)
#define COUTB(x) cout << (x) << "\n"
#define COUTS(x) cout << (x) << " "
#define PB push_back
#define SORT(obj) sort((obj).begin(), (obj).end())
#define SORTR(obj) sort((obj).begin(), (obj).end(), greater<>())
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define PI (acos(-1))
/***** MAIN *****/
signed main() {
  int n;
  cin >> n;
  vector<int> creatures(n);
  for(int i = 0; i < n; ++i) {
    cin >> creatures[i];
  }
  SORT(creatures);
  int c_sum[n];
  for(int i = 0; i < n; ++i) {
    if(i == 0) c_sum[i] = creatures[i];
    else c_sum[i] = c_sum[i-1] + creatures[i];
  }
  int ans = 1;
  for(int i = n-2; i >= 0; --i) {
    if(c_sum[i]*2 < creatures[i+1]) break;
    ++ans;
  }
  cout << ans;
  cout << "\n";
  return 0;
}
/***** MAIN *****/
