#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#define MAX_INT ((1 << 31) - 1);

using namespace std;

ifstream fin("../data.txt");

int n, x, sum, ans, diff;
vector<int> v;

int main() {

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }

  ans = MAX_INT;
  for (int i = -100; i <= 100; i++) {
    sum = 0;
    for (int j = 0; j < n; j++) {
      diff = v[j] - i;
      sum += diff*diff;
    }
    if (sum < ans) ans = sum;
  }

  cout << ans;
  return 0;
}
