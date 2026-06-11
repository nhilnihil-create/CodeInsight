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
  string A, B, C;
  cin >> A >> B >> C;
  if (A[A.size() - 1] == B[0] && B[B.size() - 1] == C[0]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}