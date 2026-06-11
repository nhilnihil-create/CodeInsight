#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const int INF = 1e9;

int main(int argc, const char * argv[]) {
  int n, k;
  cin >> n >> k;

  int ans = n;
  vector<int> list(n);
  for (int i = 0; i < n; i++) {
    cin >> list[i];
  }
  sort(list.begin(), list.end());

  int sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (sum + list[i] < k) {
      sum += list[i];
    } else {
      ans = min(ans, i);
    }
  }
  cout << ans << endl;
  return 0;
}