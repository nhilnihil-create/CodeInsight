#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n; cin >> n;
  vector<long long> a(n), b(n);
  long long res = 0;
  for (int i = 0; i < n; i++) {
  	cin >> a[i] >> b[i];
  }
  for (int i = n - 1; i >= 0; i--) {
  	res += (b[i] - (a[i] + res) % b[i]) % b[i];
  }
  cout << res << endl;
}
