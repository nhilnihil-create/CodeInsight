#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>
#include <fstream>
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repr(i,n) for(int i = (n); i > -1; i--)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const double EPS = 1e-9;


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin>>n;
  int a[n];
  rep(i,n) cin>>a[i];
  ll sum = 0;
  rep(i,n) sum += a[i];
  ll mi = 1e16;
  ll x = 0;
  ll y;
  rep(i,n-1) {
    x += a[i];
    y = sum - x;
    mi = min(mi, abs(x-y));
  }
  cout << mi << endl;

  return 0;
}
