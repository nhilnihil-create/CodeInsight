#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int maxA = 0;
  int pointB = 0;
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    if (maxA < a) {
      maxA = a;
      pointB = b;
    }
  }
  cout << maxA + pointB << endl;
  return 0;
}