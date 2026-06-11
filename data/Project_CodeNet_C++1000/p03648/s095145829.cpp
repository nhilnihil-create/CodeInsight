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

int main(int argc, char const* argv[])
{
  ll k;
  cin >> k;
  FOR(n, 2, 51){
    ll rem = k % n;
    ll base = (k - rem) / n;
    vector<ll> vec = vector<ll>(n, 0);
    rep(i, n){
      vec[i] = i + base;
    }
    rep(i, rem){
      vec[i] += n;
      rep(j, n){
        if(i != j)vec[j]--;
      }
    }
    bool flag = true;
    rep(i, n){
      if(vec[i] > (ll)1e16 + 1000){
        flag = false;
        break;
      }
    }
    if(flag){
      cout << n << endl;
      rep(i, n){
        cout << vec[i];
        if(i == n - 1)cout << endl;
        else cout << " ";
      }
      return 0;
    }
  }
	return 0;
}
