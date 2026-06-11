#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, sum;
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    int min, max;
    cin >> min >> max;
    sum += max - min + 1;
  }
  
  cout << sum << endl;
}
