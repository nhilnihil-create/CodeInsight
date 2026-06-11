#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

int main() {
  int N, a{};
  bitset<8> b;
  cin >> N;
  while (cin >> N) {
    if (N < 3200) b.set(N/400);
    else ++a;
  }
  cout << max(1ul, b.count()) << " " << b.count() + a << endl;
}
