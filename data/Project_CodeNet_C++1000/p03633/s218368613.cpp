#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

long long lcm(long long a, long long b) { 
  // long long g = gcd(a, b);
  return a / gcd(a, b) * b; }

int main() {
  int N;
  cin >> N;
  vector<long long> T(N);
  for (int i = 0; i < N; i++) {
    cin >> T.at(i);
  }
  long long aa = 1LL;
  for (int i = 0; i < T.size(); i++) {
    aa = lcm(T.at(i), aa);
  }
  cout << aa << endl;
}