#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

// 4近傍、8近傍
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
  // 入力
  string s;
  cin >> s;

  // やるだけ
  string t = s;
  reverse(t.begin(), t.end());
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == 'b') t[i] = 'd';
    else if (t[i] == 'd') t[i] = 'b';
    else if (t[i] == 'p') t[i] = 'q';
    else t[i] = 'p';
  }

  // 解答
  cout << (s == t ? "Yes" : "No") << endl;

  return 0;
}
