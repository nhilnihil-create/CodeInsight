#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// #define int long long

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
  int k;
  string s;
  cin >> s;
  cin >> k;
  int slen = s.length();
  REP(i,slen-1) {
    if(s[i]=='a') continue;
    int disToA = 'z' + 1 - s[i];
    if(disToA <= k) {
      k -= disToA;
      s[i] = 'a';
    }
    if(k == 0) break;
  }
  
  k %= 26;
  int disToA = 'z' + 1 - s[slen-1];
  if(k < disToA) {
    s[slen-1] = s[slen-1] + k;
  } else {
    s[slen-1] = 'a' + (k - disToA);
  }
  cout << s;
  
  cout << "\n";
  return 0;
}
/***** MAIN *****/
