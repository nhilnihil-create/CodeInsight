#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>
 
#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll solve(ll a, ll b) {
  if (!a) return -b;
  return solve(b % a, a) + b / a * 2 * a;
}

int main() {
  ll n, x;
  scanf("%lld%lld", &n, &x);
  printf("%lld\n", n + solve(x, n - x));
  return 0;
}
