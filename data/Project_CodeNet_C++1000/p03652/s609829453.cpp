// includes
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <climits>
#include <bitset>
#include <list>
#include <random>

// macros
#define ll long long int
#define pb emplace_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())

using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1e9 + 7;

// solve
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}

int a[301][301];

int main(int argc, char const* argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  rep(i, n){
    rep(j, m)cin >> a[i][j], a[i][j]--;
  }
  if(n == 1){
    cout << 1 << endl;
    return 0;
  }
  int res = inf;
  vector<bool> mask(m, true);
  for(int i = 0; i < m - 1; i++){
    vector<int> cnt(m, 0);
    for(int j = 0; j < n; j++){
      for(int k = 0; k < m; k++){
        if(mask[a[j][k]]){
          cnt[a[j][k]]++;
          break;
        }
      }
    }
    res = min(res, *max_element(all(cnt)));
    mask[max_element(all(cnt)) - cnt.begin()] = false;
  }
  cout << res << endl;
	return 0;
}
