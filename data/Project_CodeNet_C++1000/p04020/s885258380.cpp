#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;

typedef long long ll;

ll arr [MAX_N];

int main () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += arr[i] / 2;
    arr[i] %= 2;
    if (arr[i] == 1 && arr[i + 1] >= 1) {
      arr[i]--;
      arr[i + 1]--;
      ans++;
    }
  }
  cout << ans << endl;
}
