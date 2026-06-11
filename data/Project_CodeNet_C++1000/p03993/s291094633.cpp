#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[arr[i]] == i) ans++;
  }
  ans /= 2;

  cout << ans << endl;
}
