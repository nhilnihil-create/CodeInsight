#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> point(N);
  int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> point[i];
    sum += point[i];
  }
  
  sort(point.begin(), point.end());
  
  if (sum % 10) {
    cout << sum << endl;
  } else {
    int i = 0;
    while (i < N) {
      if (point[i] % 10) {
        sum -= point[i];
        break;
      }
      i++;
    }
    if (i == N) {
      cout << 0 << endl;
    } else {
      cout << sum << endl;
    }
  }
  
}