#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n = 0;
  long long a = 0, b = 0;
  cin >> n >> a >> b;
  vector<long long> x(n);
  for (int i=0; i<n; i++) {
    cin >> x.at(i);
  }
  long long ans = 0;
  for (int i=1; i<n; i++) {
    long long dif = x.at(i) - x.at(i-1);
    if (dif * a <= b) {
      ans += dif * a;
    } else {
      ans += b;
    }
  }
  cout << ans << endl;
  return 0;
}
