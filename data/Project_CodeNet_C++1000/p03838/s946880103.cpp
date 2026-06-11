#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int x, y, num1 = INT_MAX, num2 = INT_MAX, num3 = INT_MAX, num4 = INT_MAX;
  cin >> x >> y;
  if (-x<=-y) num1 = -y+x+2; // 最初と最後でBを押す
  if (-x<=y) num2 = y+x+1; // 最初だけBを押す
  if (x<=-y) num3 = -y-x+1; // 最後だけBを押す
  if (x<=y) num4 = y-x; // Bを押さない
  cout << min(num1, min(num2, min(num3, num4))) << endl;
}