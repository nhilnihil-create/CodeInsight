#include <iostream>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int ans{K};
  while(--N) {
    ans *= K-1;
  }
  cout << ans << endl;
  return 0;
}
