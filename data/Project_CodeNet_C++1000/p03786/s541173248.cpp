#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

typedef long long ll;

int n;
int arr [MAX_N];

bool can (int idx) {
  ll sz = arr[idx];

  for (int i = 0; i < n; i++) {
    if (i != idx) {
      if (arr[i] <= 2 * sz) {
        sz += arr[i];
      } else {
        return false;
      }
    }
  }

  return true;
}

int main () {
  ios::sync_with_stdio(false);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);

  if (can(0)) {
    cout << n << endl;
    return 0;
  }

  int ans = 0;
  for (int k = 1 << 17; k != 0; k /= 2) {
    if (ans + k < n && !can(ans + k)) {
      ans += k;
    }
  }

  cout << n - (ans + 1) << endl;
}
