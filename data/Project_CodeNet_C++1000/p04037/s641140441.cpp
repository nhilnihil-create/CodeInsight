#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

int main() {
  int N = in();
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    A[i] = in();
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());

  int r = 0, c = 0;
  while (true) {
    const int rr = r + 1, cc = c + 1;
    if (cc >= N || rr >= A[cc]) {
      break;
    }
    r = rr; c = cc;
  }

  int rig = 0;
  while (true) {
    if (c + rig + 1 >= N || r >= A[c + rig + 1]) {
      break;
    }
    ++rig;
  }

  int upp = A[c] - 1 - r;

  if (rig % 2 == 0 && upp % 2 == 0) {
    puts("Second");
  } else {
    puts("First");
  }

  return 0;
}
