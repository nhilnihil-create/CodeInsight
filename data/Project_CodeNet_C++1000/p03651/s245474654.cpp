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
  int n, k;
  cin >> n >> k;
  int max_in = 0;
  int G = 0;
  REP(i,n) {
    int t_in;
    cin >> t_in;
    if(G == 0) {
      G = t_in;
    } else {
      G = __gcd(G, t_in);
    }
    max_in = max(max_in, t_in);
  }
  if(k > max_in) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  if(k % G) {
    cout << "IMPOSSIBLE";
  } else {
    cout << "POSSIBLE";
  }

  cout << "\n";
  return 0;
}
/***** MAIN *****/
