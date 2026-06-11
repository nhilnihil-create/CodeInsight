#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> L(2 * N);
  rep(i, 2 * N) { cin >> L[i]; }
  sort(L.begin(), L.end());
  int answer = 0;
  for (int i = 0; i < 2 * N; i += 2) {
    answer += L[i];
  }
  cout << answer << endl;
  return 0;
}
