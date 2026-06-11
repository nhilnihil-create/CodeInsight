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


int main(int argc, char const* argv[])
{
  int n; cin >> n;
  vector<int> x(n); cin >> x;
  rep(i, n)x[i]--;
  
  vector<int> res(n * n, - 1);

  vector<int> e(n); rep(i, n)e[i] = i;
  sort(all(e), [&](int a, int b){
    return x[a] < x[b];
  });

  rep(i, n - 1)if(x[e[i]] == x[e[i+1]]){
    cout << "No" << endl;
    return 0;
  }

  rep(i, n){
    res[x[e[i]]] = e[i];
    int curr = 0;
    for(int j = 0; j < e[i]; j++){
      if(curr == n * n){
        cout << "No" << endl;
        return 0;
      }
      for(int k = curr; k < n * n; k++){
        if(res[k] == -1 && x[e[i]] > k){
          res[k] = e[i];
          curr = k + 1;
          break;
        }
        if(k + 1 == n * n){
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  rrep(i, n){
    int curr = n * n - 1;
    rep(j, n - e[i] - 1){
      if(curr < 0){
        cout << "No" << endl;
        return 0;
      }
      for(int k = curr; k >= 0; k--){
        if(res[k] == -1 && x[e[i]] < k){
          res[k] = e[i];
          curr = k - 1;
          break;
        }
        if(k == 0){
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
  rep(i, sz(res))res[i] += 1;
  cout << res << endl;
  return 0;
}
