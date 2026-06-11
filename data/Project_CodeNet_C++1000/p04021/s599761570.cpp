#include <iostream>
#include <map>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

int main () {
  int n;
  cin >> n;

  map<int, int> compr;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    compr[arr[i]] = 0;
  }

  int cur = 0;
  for (auto it = compr.begin(); it != compr.end(); it++) {
    it->second = cur;
    cur++;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = compr[arr[i]];
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 != i % 2) {
      ans++;
    }
  }
  cout << ans / 2 << endl;
}
