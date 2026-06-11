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
  string A, B;
  cin >> A >> B;
  if (A.size() < B.size()) {
    cout << "LESS" << endl;
  } else if (A.size() > B.size()) {
    cout << "GREATER" << endl;
  } else {
    for (int i = 0; i < A.size(); i++) {
      if (A[i] < B[i]) {
        cout << "LESS" << endl;
        return 0;
      } else if (A[i] > B[i]) {
        cout << "GREATER" << endl;
        return 0;
      } else {
        continue;
      }
    }
    cout << "EQUAL" << endl;
  }
  return 0;
}