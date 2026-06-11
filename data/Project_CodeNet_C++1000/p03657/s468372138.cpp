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
  ll A, B;
  cin >> A >> B;
  if ((A + B) % 3 == 0 || A % 3 == 0 || B % 3 == 0) {
    cout << "Possible" << endl;
  } else
    cout << "Impossible" << endl;
  return 0;
}