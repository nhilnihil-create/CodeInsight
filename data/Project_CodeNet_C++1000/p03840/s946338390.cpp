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
  ll a[7];
  rep(i, 7){
    cin >> a[i];
  }
  ll res = 0;
  res += 2 * a[1];
  if(a[0] == 0){
    res += 4 * (a[3] / 2);
    res += 4 * (a[4] / 2);
  }else if(a[3] == 0){
    res += 4 * (a[0] / 2);
    res += 4 * (a[4] / 2);
  }else if(a[4] == 0){
    res += 4 * (a[0] / 2);
    res += 42 * (a[3] / 2);
  }else{
    res += 4 * ((a[0] - 1) / 2);
    res += 4 * ((a[3] - 1) / 2);
    res += 4 * ((a[4] - 1) / 2);
    int num = (a[0] % 2) + (a[3] % 2) + (a[4] % 2);
    if(num == 3 || num == 2)res += 6;
    else if(num == 1)res += 8;
    else res += 12;
  }
  cout << res / 2 << endl;
	return 0;
}
