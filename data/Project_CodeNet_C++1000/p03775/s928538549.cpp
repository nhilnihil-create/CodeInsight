#include <bits/stdc++.h>
using namespace std;

long long MIN = 99999999;

template <typename T>
string ToString(const T& n) {
  ostringstream stm;
  stm << n;
  return stm.str();
}

void divisor(long long n) {
  long long t = sqrt(n);
  for (long long i = 1; i <= t; i++) {
    if (n % i == 0) {
      string a, b;
      a = ToString(i);
      b = ToString(n/i);
      if (max(a.size(), b.size()) < MIN) {
        MIN = max(a.size(), b.size());
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  long long N;
  cin >> N;
  divisor(N);
  cout << MIN << endl;
}