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
  string S;
  cin >> S;
  if (S.substr(0, 4) == "YAKI") {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}