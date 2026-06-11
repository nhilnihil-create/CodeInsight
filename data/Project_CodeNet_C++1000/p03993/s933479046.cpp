#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  int ans{};
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    if (a[a[i]-1]-1 == i) ++ans;
  }
  cout << ans << endl;
  return 0;
}
