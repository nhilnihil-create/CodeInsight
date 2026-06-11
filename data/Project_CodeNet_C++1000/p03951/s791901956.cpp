#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int N, i;
  string s, t;
  cin >> N >> s >> t;
  for (i = N; i; --i)
    if (equal(begin(s) + N - i, end(s), begin(t))) break;
  cout << 2 * N - i << endl;
  return 0;
}
