#include <algorithm>
#include <cassert>
// #include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
// #include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);
*/
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;
typedef pair<int, ppiipii> pippiipii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> ppiii;
typedef pair<int, ppiii> pippiii;
typedef pair<int, ll> pill;
typedef pair<int, double> pid;
typedef pair<string, string> pss;
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef long double ld;

int n, m;
int x[100005];
int y[100005];

const int MOD = 1000000007;

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  for(int i = 0; i < m; i++) {
    scanf("%d", &y[i]);
  }
  ll xx = 0;
  {
    int s = n-1;
    for(int i = n-1; i >= 0; i--) {
      xx += s * (ll)x[i];
      xx %= MOD;
      xx += MOD;
      xx %= MOD;
      s -= 2;
    }
  }
  ll yy = 0;
  {
    int s = m-1;
    for(int i = m-1; i >= 0; i--) {
      yy += s * (ll)y[i];
      yy %= MOD;
      yy += MOD;
      yy %= MOD;
      s -= 2;
    }
  }
  printf("%lld\n", (xx*yy) % MOD);
}
