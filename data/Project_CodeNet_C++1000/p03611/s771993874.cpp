#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(1e5+2, 0);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++vec[a];
  }

  int ans = 0;
  for (int i = 1; i <= 1e5; ++i)
    ans = max(ans, vec[i] + vec[i-1] + vec[i+1]);

  cout << ans << endl;
}

