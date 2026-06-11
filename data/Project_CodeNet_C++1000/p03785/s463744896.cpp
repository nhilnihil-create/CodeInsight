#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, c, k;
  cin >> n >> c >> k;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);

  int ans = 0;
  int cur_t = -1, cap = 0;
  for (int i = 0; i < n; i++) {
    if (cur_t < arr[i]) {
      ans++;
      cur_t = arr[i] + k;
      cap = 1;
    } else {
      cap++;
    }

    if (cap == c) {
      cur_t = -1;
      cap = 0;
    }
  }

  cout << ans << endl;
}
