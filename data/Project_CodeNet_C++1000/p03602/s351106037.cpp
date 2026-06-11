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

int g[400][400];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%d", &g[i][j]);
    }
  }
  ll ret = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      bool needed = true;
      for(int k = 0; k < n; k++) {
        if(g[i][k] + g[k][j] < g[i][j]) {
          printf("-1\n");
          return 0;
        }
        if(k != i && k != j && g[i][k] + g[k][j] == g[i][j]) {
          needed = false;
        }
      }
      if(needed) {
        ret += g[i][j];
      }
    }
  }
  printf("%lld\n", ret/2);
}
