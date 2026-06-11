#include <cmath>
#include <iostream>
using namespace std;
int main() {
  long long N, m;
  cin >> N;
  for (auto a = 1ll; a * a <= N; ++a) if (!(N % a)) m = a;
  cout << int(log10(N / m)) + 1 << endl;
}
