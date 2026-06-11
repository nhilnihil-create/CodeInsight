#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#define MOD (1000000007l)
#define rep(i, n) for(long i = 0; i < n; i++)

using namespace std;

long gcd(long a, long b) {
  while (true) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    a %= b;
  }
}

int main(void) {
  long N, X;
  cin >> N >> X;
  cout << (N / gcd(N, X) - 1) * 3 * gcd(N, X) << endl; 
  return 0;
}
