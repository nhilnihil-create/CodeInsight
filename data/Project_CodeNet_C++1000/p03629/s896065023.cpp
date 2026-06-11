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
#define LB(c,x) lower_bound(ALL(c),x)-(c).begin()
#define UB(c,x) upper_bound(ALL(c),x)-(c).begin()
#define COUNT(c,x) (int)(UB(c,x)-LB(c,x))
#define EXIST(s,e) (s).find(e)!=(s).end()

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

int init_len(vector<int>& len, const string& str)
{
  int k = 0;
  set<char> st;
  rrep(i, 0, SIZE(str)) {
    st.insert(str[i]);
    if (SIZE(st) == 26) {
      k++;
      st.clear();
    }
    len[i] = k;
  }
  return k;
}


signed main()
{
  // string filename; cin >> filename;
  // ifstream in(filename);
  // cin.rdbuf(in.rdbuf());

  string A; cin >> A;

  vector<int> len(SIZE(A));
  int k = init_len(len, A);

  vector< vector<int> > p(26, vector<int>());
  rep(i, 0, SIZE(A)) {
    p[A[i]-'a'].push_back(i);
  }

  int now = 0;
  string ans = "";
  rep(i, 0, k+1) {
    debug(i)
    rep(c, 0, 26) {
      int lb = LB(p[c],now);
      if (lb == SIZE(p[c])) {
        ans += c + 'a';
        break;
      }
      int idx = p[c][lb];
      if (len[idx+1] + 1 == k - i) {
        ans += c + 'a';
        now = idx + 1;
        break;
      }
    }
  }

  cout << ans << endl;

  return 0;
}