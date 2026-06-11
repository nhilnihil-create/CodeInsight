#include <iostream>
#include <vector>

using namespace std;
typedef long long lint;

int main() {
  int N;
  cin >> N;
  vector<int> ps(N);
  for (int i = 0; i < N; i++) {
    cin >> ps[i];
    --ps[i];
  }
  int ans = 0;
  for (int i = 0; i < N-1; i++) {
    if (ps[i] == i) {
      ++ans;
      swap(ps[i], ps[i+1]);
    }
  }
  if (ps[N-1] == N-1) ++ans;
  cout << ans << endl;
  return 0;
}