#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int k, t;
  cin >> k >> t;
  vector<int> a(t);
  int maxi = 0;
  for(int i = 0; i < t; i++) {
    cin >> a[i];
    maxi = max(maxi, a[i]);
  }
  if(k % 2 == 0) {
    if(maxi > k / 2) {
      cout << (maxi - k / 2) * 2 - 1 << endl;
    } else {
      cout << 0 << endl;
    }
  } else {
    if(maxi > (k + 1) / 2) {
      cout << (maxi - (k + 1) / 2) * 2 - 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }

  return 0;
}