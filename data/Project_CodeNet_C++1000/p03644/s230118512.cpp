#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int maxIndex = 0;
  int max = 0;
  for (int i = 1; i <= N; i++) {
    int count = 0;
    int j = i;
    while (j % 2 == 0) {
      j >>= 1;
      count++;
    }
    if (max <= count) {
      max = count;
      maxIndex = i;
    }
  }
  
  cout << maxIndex << endl;
}