#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int ans = 0;
  int current = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'I') {
      current++;
    } else {
      current--;
    }

    ans = max(ans, current);
  }
  cout << ans << endl;
  return 0;
}