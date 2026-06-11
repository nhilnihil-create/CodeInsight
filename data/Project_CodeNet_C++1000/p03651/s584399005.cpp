#include <iostream>
#include <cassert>
#include <numeric>
using namespace std;

int main () {
  long long N, K;
  cin >> N >> K;
  long long max_ = 0;
  long long gcd_ = 0;
  for (long long i = 0; i < N; i++){
    long long a;
    cin >> a;
    if (i == 0) gcd_ = a;
    else gcd_ = gcd(a, gcd_);
    max_ = max(a, max_);
  }
  if (K <= max_ && K % gcd_ == 0) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
}