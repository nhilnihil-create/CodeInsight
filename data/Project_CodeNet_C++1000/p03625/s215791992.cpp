#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;

  map<int, int, greater<int>> A;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[a]++;
  }
  
  int sideA = 0;
  int sideB = 0;

  for (auto item: A) {
    if (4 <= item.second) {
      if (sideA == 0) {
        sideA = item.first;
      }
      if (sideB == 0) {
        sideB = item.first;
        break;
      }
    } else if (2 <= item.second) {
      if (sideA == 0) {
        sideA = item.first;
      } else if (sideB == 0) {
        sideB = item.first;
        break;
      }
    }
  }

  long long answer = (long long) sideA * sideB;
  
  cout << answer << endl;

  return 0;

}