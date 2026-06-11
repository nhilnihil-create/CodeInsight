#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  long long N, M;
  cin >> N >> M;

  if (N >= M / 2) cout << M / 2 << endl;
  else {
    long long m = M - (2 * N);
    m /= 4;
    cout << N + m << endl;
  }

  return 0;
}
