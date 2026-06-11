// includes
#include <bits/stdc++.h>
using namespace std;

// macros
#define pb emplace_back
#define mk make_pair
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define irep(itr, st) for(auto itr = (st).begin(); itr != (st).end(); ++itr)
#define irrep(itr, st) for(auto itr = (st).rbegin(); itr != (st).rend(); ++itr)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define bit(n) (1LL<<(n))
// functions
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for(auto &v: vec)is >> v; return is;}
template <typename T> ostream &operator<<(ostream &os, const vector<T>& vec){for(int i = 0; i < vec.size(); i++){ os << vec[i]; if(i + 1 != vec.size())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p){os << p.first << " " << p.second; return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const unordered_map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
//  types
using ll = long long int;
using P = pair<int, int>;
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1000000007;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
// io
struct fast_io{
  fast_io(){ios_base::sync_with_stdio(false); cin.tie(0); cout << fixed << setprecision(20);}
} fast_io_;

ll dp[100010][3];

int main(int argc, char const* argv[])
{
  int n; cin >> n;
  vector<ll> a(n);
  vector<string> op(n-1);
  cin >> a[0];
  rep(i, n - 1)cin >> op[i] >> a[i+1];
  rep(i, n)rep(j, 3)dp[i][j] = - linf;
  dp[0][0] = a[0];
  rep(i, n - 1){
    if(op[i] == "+"){
      chmax(dp[i+1][0], dp[i][0] + a[i+1]);
      chmax(dp[i+1][1], dp[i][1] - a[i+1]);
      chmax(dp[i+1][2], dp[i][2] + a[i+1]);
      chmax(dp[i+1][1], dp[i][2] + a[i+1]);
      chmax(dp[i+1][0], dp[i][1] - a[i+1]);
    }else{
      chmax(dp[i+1][0], dp[i][0] - a[i+1]);
      chmax(dp[i+1][1], dp[i][1] + a[i+1]);
      chmax(dp[i+1][2], dp[i][2] - a[i+1]);
      chmax(dp[i+1][1], dp[i][2] - a[i+1]);
      chmax(dp[i+1][0], dp[i][1] + a[i+1]);
      chmax(dp[i+1][1], dp[i][0] - a[i+1]);
      chmax(dp[i+1][2], dp[i][1] + a[i+1]);
      chmax(dp[i+1][2], dp[i][2] - a[i+1]);
    }
  }
  cout << dp[n-1][0] << endl;
  return 0;
}
