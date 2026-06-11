#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const long long LINF = (1LL << 60);

int main() {
  int n;
  cin >> n;

  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  long long sum = 0, ans = LINF, cnt = 0;
  // patern of +-+-+-...
  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (i & 1) {
      if (sum >= 0) {
        cnt += abs(sum) + 1;
        sum = -1;
      }
    } else {
      if (sum <= 0) {
        cnt += abs(sum) + 1;
        sum = 1;
      }
    }
  }
  ans = min(ans, cnt);

  sum = 0;
  cnt = 0;
  // patern of -+-+-+...
  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (!(i & 1)) {
      if (sum >= 0) {
        cnt += abs(sum) + 1;
        sum = -1;
      }
    } else {
      if (sum <= 0) {
        cnt += abs(sum) + 1;
        sum = 1;
      }
    }
  }
  ans = min(ans, cnt);

  cout << ans << endl;

  return 0;
}