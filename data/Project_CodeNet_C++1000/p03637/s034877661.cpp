#include <iostream>
#include <vector>
using namespace std;

int dist(int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}

int main() {
  int N;
  cin >> N;
  int x4 = 0;
  int x2 = 0;
  int x1 = 0;

  for (int i = 0; i < N; i++) {
    int d;
    cin >> d;
    if (d % 2 == 1) {
      x1++;
    } else if (d % 4 == 0) {
      x4++;
    } else {
      x2++;
    }
  }
  x1 += x2 % 2;
  if (x1 - 1 <= x4) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
