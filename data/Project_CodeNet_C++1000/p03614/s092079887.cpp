#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>
// #include <fstream>
#define int long long int
#define mod(x) ((x % MOD) + MOD) % MOD
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);--i)

#define ALL(c) (c).begin(),(c).end()
#define SIZE(c) (int)((c).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define SORT(c) sort(ALL(c))
#define LB(c,x) lower_bound(ALL(c),x)
#define UB(c,x) upper_bound(ALL(c),x)
#define COUNT(c,x) (int)(UB(c,x)-LB(c,x))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;

using namespace std;

typedef pair<int,int> P;
struct edge {
  int to, cost;
};

const int INF = 1e18;
const int MOD = 1e9+7;

template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << " ";
  }
  return s;
}


signed main()
{
  // string filename; cin >> filename;
  // ifstream in(filename);
  // cin.rdbuf(in.rdbuf());

  int N; cin >> N;
  vector<int> p(N);
  rep(i, 0, N) {
    cin >> p[i];
  }

  int ans = 0;
  rep(i, 0, N-1) {
    if (i+1 == p[i]) {
      ans++;
      swap(p[i], p[i+1]);
    }
  }
  if (N == p[N-1]) {
    ans++;
  }

  cout << ans << endl;

  return 0;
}
