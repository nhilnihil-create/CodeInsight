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
typedef pair<double, double> Pd;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;

// solve

int main(int argc, char const* argv[])
{
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a, b;
  rep(i, n){
    ll x, y;
    cin >> x >> y;
    a.pb(x);
    b.pb(y);
  }
  int kl = 0;
  vector<int> kbit;
  ll ktmp = k;
  while(ktmp){
    kbit.pb(ktmp % 2);
    ktmp /= 2;
    kl++;
  }
  ll res = 0;
  rep(i, kl+1){
    ll ku;
    if(i == kl){
      ku = k;
    }else{
      if(kbit[i] == 0)continue;
      ku = k & ~((ll)1 << i);
      ku = ku | (((ll)1 << i) - 1);
    }
    ll rtmp = 0;
    rep(j, n){
      ll kutmp = ku, atmp = a[j];
      bool flag = true;
      while(atmp){
        if(atmp % 2 == 1 && !(kutmp % 2 == 1)){
          flag = false;
          break;
        }
        atmp /= 2;
        kutmp /= 2;
      }
      if(flag){
        rtmp += b[j];
      }
    }
    res = max(res, rtmp);
  }

  cout << res << endl;
	return 0;
}
