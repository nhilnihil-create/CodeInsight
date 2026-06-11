#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  vector<int> L(N);
  rep(i, N) cin >> L[i];
  sort(L.rbegin(), L.rend());
  int answer = 0;
  rep(i, K) answer += L[i];
  cout << answer << endl;
  return 0;
}
