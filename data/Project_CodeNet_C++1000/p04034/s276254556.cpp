#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
  int N, M, x, y;
  cin >> N >> M;
  vector<int> b(N), n(N,1);
  b[0] = 1;
  for (int i = 0; i < M; i++) {
    cin >> x >> y;
    b[y-1] = b[y-1] || b[x-1];
    --n[x-1], ++n[y-1];
    if (!n[x-1]) b[x-1] = 0;
  }
  cout << accumulate(begin(b),end(b),0) << endl;
}
