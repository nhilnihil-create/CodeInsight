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

// macros
#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a); i<(b);++i)
#define rep(i, n) FOR(i, 0, n)

using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;

// solve
bool comp(const Pl &a, const Pl &b){
  return a.first > b.first;
}

int main(int argc, char const* argv[])
{
  int w, h;
  cin >> w >> h;
  vector<Pl> vec;
  rep(i, w){
    ll x;
    cin >> x;
    vec.pb(mk(x, 0));
  }
  rep(i, h){
    ll x;
    cin >> x;
    vec.pb(mk(x, 1));
  }
  sort(vec.begin(), vec.end(), comp);
  ll res = 0;
  int vnum = 0;
  int rnum = 0;
  rep(i, vec.size()){
    if(vec[i].second == 0){
      res += (vnum + 1) * vec[i].first;
      rnum++;
    }else{
      res += (rnum + 1) * vec[i].first;
      vnum++;
    }
  }
  cout << res << endl;
	return 0;
}
