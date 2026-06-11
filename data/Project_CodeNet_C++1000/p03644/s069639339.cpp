#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;

  int Max = 0;
  int max_num = 1;
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    int j = i;
    while (j % 2 == 0) {
      j *= 0.5;
      cnt++;
    }
    if (cnt > Max) {
      Max = cnt;
      max_num = i;
    }
  }

  cout << max_num << endl;
  return 0;
}