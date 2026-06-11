#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  char a, b;
  cin >> a >> b;
  map<char, char> m = {{'H', 'D'}, {'D', 'H'}};
  if (a == 'H') {
    cout << b << endl;
  } else {
    cout << m[b] << endl;
  }
  return 0;
}