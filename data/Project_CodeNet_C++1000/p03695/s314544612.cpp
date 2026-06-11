
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  rep(i, n) {
    int v;
    cin >> v;
    v /= 400;
    if (v >= 8) {
      mp[8]++;
    } else {
      mp[v]++;
    }
  }
  int min = 0, max = 0;

  rep(i, 8) {
    if (mp[i] != 0) {
      min++;
    }
  }

  max = min + mp[8];
  if (min == 0) {
    cout << 1 << " " << max;
  } else {
    cout << min << " " << max;
  }
  return 0;
}
