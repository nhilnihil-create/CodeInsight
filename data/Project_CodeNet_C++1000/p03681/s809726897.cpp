#include <iostream>
#include <cmath>

using namespace std;

long long fact(long long x) {
  if (x == 1)
    return 1;
  else
    return (x * fact(x - 1)) % 1000000007;
}

int main(int argc, char* argv[]) {
  long long N, M;
  cin >> N >> M;

  if (abs(N - M) >= 2) {
    cout << 0 << endl;
    return 0;
  }

  long long ret = 0;
  if (N == M) {
    ret += (fact(N) * fact(M) * 2) % 1000000007;
  } else {
    ret += (fact(N) * fact(M)) % 1000000007;
  }

  cout << ret << endl;

  return 0;
}