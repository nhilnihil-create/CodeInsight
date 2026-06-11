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

vector<int> edge[100001];
struct Qu{
  int v, d, c;
  Qu(){}
  Qu(int v, int d, int c): v(v), d(d), c(c){}
};

int dp[100001][11];

void update(int v, int d, int c){
  if(d < 0)return;
  if(dp[v][d] != 0)return;
  int tc = d;
  while(tc >= 0 && dp[v][tc] == 0)dp[v][tc] = c, tc--;
  for(auto e: edge[v]){
    update(e, d - 1, c);
  }
}

int main(int argc, char const* argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  rep(i, m){
    int a, b;
    cin >> a >> b, a--, b--;
    edge[a].pb(b);
    edge[b].pb(a);
  }
  int q;
  cin >> q;
  vector<Qu> vec(q);
  rep(i, q){
    int v, d, c;
    cin >> v >> d >> c, v--;
    vec[i] = Qu(v, d, c);
  }
  for(int i = 0; i < n; i++){
    for(int j = 0;  j < 11; j++){
      dp[i][j] = 0;
    }
  }
  reverse(all(vec));
  for(int i = 0; i < q; i++){
    int v = vec[i].v, d = vec[i].d, c = vec[i].c;
    update(v, d, c);
  }
  for(int i = 0; i < n; i++){
    cout << dp[i][0] << endl;
  }
	return 0;
}
