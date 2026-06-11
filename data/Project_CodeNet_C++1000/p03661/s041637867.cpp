#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

ll arr [MAX_N];
ll pref [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    pref[i] = arr[i] + pref[i - 1];
  }

  ll mn = 1e18;
  for (int i = 1; i < n; i++) {
    mn = min(mn, abs(pref[i] - (pref[n] - pref[i])));
  }
  cout << mn << endl;
}
