#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int light = 0;
  int count = 0;
  vector<int>A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++) {
    count++;
    light = A.at(light)-1;
    if (light == 1){
      cout << count << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}