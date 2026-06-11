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
#define typeof(x) __typeof__(x)
#define int long long int
#define mod(x) ((x % MOD) + MOD) % MOD
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);--i)

#define ALL(c) (c).begin(),(c).end()
#define SIZE(c) (int)((c).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define SORT(c) sort(ALL(c))
#define LB(c,x) (int)(lower_bound(ALL(c),x)-(c).begin())
#define UB(c,x) (int)(upper_bound(ALL(c),x)-(c).begin())
#define COUNT(c,x) (int)(UB(c,x)-LB(c,x))
#define UNIQUE(c) SORT(c); (c).erase(unique(ALL(c)),(c).end());

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
  vector<int> a(N);
  rep(i, 0, N) {
    cin >> a[i];
  }

  vector<int> s(N+1);
  s[0] = 0;
  rep(i, 1, N+1) {
    s[i] = s[i-1] + a[i-1];
  }

  int m = INF;
  rep(i, 1, N) {
    m = min(m, abs(s[N] - 2*s[i]));
  }

  cout << m << endl;

  return 0;
}
