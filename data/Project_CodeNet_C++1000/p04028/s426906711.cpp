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

int dp[5001];
int ndp[5001];

char buf[5005];

const int MOD = 1000000007;

int main() {
  int n;
  scanf("%d\n%s", &n, buf);
  dp[strlen(buf)] = 1;
  for(int numOp = n; numOp > 0; numOp--) {
    memset(ndp, 0, sizeof(dp));
    for(int i = 0; i <= numOp; i++) {
      ndp[i+1] += 2 * dp[i];
      ndp[i+1] %= MOD;
      ndp[max(0,i-1)] += dp[i];
      ndp[max(0,i-1)] %= MOD;
    }
    for(int a = 0; a <= numOp; a++) {
      dp[a] = ndp[a];
    }
  }
  printf("%d\n", dp[0]);
}
