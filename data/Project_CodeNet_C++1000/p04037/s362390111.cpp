#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

void win () {
  cout << "First" << endl;
  exit(0);
}

void lose () {
  cout << "Second" << endl;
  exit(0);
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  sort(arr + 1, arr + n + 1, greater<int>());

  arr[n + 1] = -5;
  for (int i = 1; true; i++) {
    if (i + 1 > arr[i + 1]) {
      int upd = arr[i] - i;
      int rgd = 0;
      for (int k = 1; true; k++) {
        if (i == arr[i + k]) rgd++;
        else break;
      }

      if (upd % 2 == 1 || rgd % 2 == 1) win();
      lose();
    }
  }
}
