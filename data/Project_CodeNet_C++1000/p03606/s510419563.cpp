#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, left, right;
  int total = 0;
  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> left >> right;
    total += right - left + 1;
  }
  cout << total << endl;

}
