#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int last;
  cin >> last;

  int last_dir = 0, ans = 1;
  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;

    if (x != last) {
      if (x < last) {
        if (last_dir == 1) {
          ans++;
          last_dir = 0;
        } else {
          last_dir = -1;
        }
      }

      if (x > last) {
        if (last_dir == -1) {
          ans++;
          last_dir = 0;
        } else {
          last_dir = 1;
        }
      }

      last = x;
    }
  }

  cout << ans << endl;
}
