#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
using int64 = long long;

int main() {
  int W, a, b;
  cin >> W >> a >> b;
  int move = abs(a - b) - W;
  if (move < 0) {
    move = 0;
  }
  cout << move << endl;
  return 0;
}