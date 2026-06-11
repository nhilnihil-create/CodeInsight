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
const int mod = 1e9 + 7;

// solve

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;
  vector<ll> t, a;
  bool invalid = false;
  rep(i, n){
    ll x;
    cin >> x;
    t.pb(x);
    if(i > 0){
      if(t[i-1] > t[i])invalid = true;
    }
  }
  rep(i, n){
    ll x;
    cin >> x;
    a.pb(x);
    if(i > 0){
      if(a[i-1] < a[i])invalid = true;
    }
  }
  if(invalid || t[n-1] != a[0]){
    cout << 0 << endl;
    return 0;
  }
  ll res = 1;
  FOR(i, 1, n - 1){
    if(t[i-1] != t[i] || a[i+1] != a[i]){
      if(t[i-1] != t[i]){
        if(t[i] > a[i]){
          cout << 0 << endl;
          return 0;
        }
      }else{
        if(a[i] > t[i]){
          cout << 0 << endl;
          return 0;
        }
      }
    }else{
      res = res * min(t[i], a[i]) % mod;
    }
  }
  cout << res << endl;
	return 0;
}
