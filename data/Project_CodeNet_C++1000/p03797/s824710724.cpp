#include <iostream>

using namespace std;

int main() {
  int64_t N, M;
  cin >> N >> M;

  int64_t dum = max((M - N * 2) / 4, int64_t(0));
  N += dum;
  M -= dum * 2;

  cout << min(N, M / 2) << endl;
}
