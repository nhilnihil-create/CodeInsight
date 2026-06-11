#include <iostream>
#define REP(i, n) for(long long i = 0; i < (n); ++i)

template <typename T> void chmax (T& a, T b) { if (a < b) a = b; }

int main () {
  int K, S;
  std::cin >> K >> S;
  int result = 0;
  REP(X, K + 1) {
      REP(Y, K + 1) {
          int Z = S - X - Y;
          if (Z >= 0 && Z <= K) ++result;
      }
  }
  std::cout << result << std::endl;
  return 0;
}