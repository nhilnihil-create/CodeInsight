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
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef long double ld;

int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  int lowest = 1 << 30;
  int ret = 0;
  int save = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &t);
    if(t - lowest > save) {
      ret = 0;
      save = t - lowest;
    }
    if(t - lowest == save) ret++;
    lowest = min(lowest, t);
  }
  printf("%d\n", ret);
}
