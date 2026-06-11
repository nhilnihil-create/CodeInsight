
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <stack>
#include <bitset>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define sz(v) (int) (v).size()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

ll ans = 10000000000000;
ll a[20];
int n, k;

int main(void) {
  cin >> n >> k;
  rep(i, 0, n) scanf("%lld", &a[i]);
  for (int i=0; i<(1<<n); i++) {
    if (__builtin_popcount(i)!=k) continue;
    ll s = 0, sum = 0;
    for (int j=0; j<n; j++) {
      if ((i>>j)&1){
        if (a[j]>s) { 
          s = a[j]; 
        } else {
          s++;
          sum += s - a[j];
        }
      } else {
        s = max(s, a[j]);
      }
    }
    ans = min(ans, sum);
  }
 
  cout << ans << "\n";

  return 0;
}
