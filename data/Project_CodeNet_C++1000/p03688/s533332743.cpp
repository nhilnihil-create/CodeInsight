#include <iostream>
#include <map>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  map<int, int> count;
  rep(i, N) {
    int A;
    cin >> A;
    count[A]++;
  }

  if (2 <= (count.rbegin()->first - count.begin()->first) || 2 < count.size()) {
    cout << "No" << endl;
    return 0;
  }

  if (count.size() == 2) {
    int B = count.rbegin()->first;
    int x = count.begin()->second;
    int y = N - x;
    if (x < B && 2 * (B - x) <= y) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {  // 1
    int B = count.begin()->first;
    if ((2 * B <= N) || (B + 1) == N) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
