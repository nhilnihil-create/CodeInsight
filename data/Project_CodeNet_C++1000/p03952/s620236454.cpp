#include <iostream>
#include <set>

using namespace std;

const int MAX_N = 3e5 + 5;

set<int> taken;
int arr [MAX_N];

void put (int pos, int val) {
  arr[pos] = val;
  taken.erase(val);
}

int main () {
  int n, x;
  cin >> n >> x;

  if (x == 1 || x == 2 * n - 1) {
    cout << "No" << '\n';
    return 0;
  }

  cout << "Yes" << '\n';

  if (n == 2) {
    cout << 1 << endl << 2 << endl << 3 << endl;
    return 0;
  }
  
  for (int i = 1; i <= 2 * n - 1; i++) {
    taken.insert(i);
  }

  if (x != 2) {
    put(n - 1, 1);
    put(n, x);
    put(n + 1, 2 * n - 1);
    put(n + 2, 2);
  } else {
    put(n - 1, 2 * n - 1);
    put(n, 2);
    put(n + 1, 1);
    put(n + 2, 2 * n - 2);
  }

  for (int i = 1; i <= 2 * n - 1; i++) {
    if (arr[i] == 0) {
      put(i, *taken.begin());
    }
    cout << arr[i] << '\n';
  }
}
