#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;
int main(int argc, const char * argv[]) {
  int N, T;
  cin >> N >> T;
  vector<int> list(N);
  for (int i = 0; i < N; i++) {
    cin >> list[i];
  }

  ll ans = 0;
  for (int i = 1; i < N; i++) {
    if (list[i] - list[i - 1] < T) {
      ans += list[i] - list[i - 1];
    } else {
      ans += T;
    }
  }
  cout << ans + T << endl;

  return 0;
}
