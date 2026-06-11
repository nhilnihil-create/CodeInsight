#include <bits/stdc++.h>
using namespace std;

// using ll = long long;
#define int long long

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, r, n) for (int i = (r); i < (n); ++i)
#define REPR(i, n) for(int i = (n); i >= 0; --i) // from n to 0
#define REPRS(i, r, n) for(int i = (n); i >= (r); --i) // from n to r
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
  string s;
  cin >> s;
  int n = s.length();
  if(n == 1) {
    cout << 1 << endl;
    return 0;
  }
  map<char, int> mp;
  REP(i,n) {
    ++mp[s[i]];
  }
  int ans = n * (n-1) / 2;
  for(char c = 'a'; c <= 'z'; ++c) {
    int count = mp[c];
    if(count < 2) continue;
    ans -= count * (count-1) / 2;
  }
  cout << ans+1;
  
  cout << "\n";
  return 0;
}
/***** MAIN *****/
