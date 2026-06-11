#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, T;
  cin >> N >> T;
  vector <int> time(N);
  for (int i = 0; i < N; i++) {
    cin >> time.at(i);
  }
  int sum = 0;
  for (int i = 0; i < N-1; i++) {
    if ((time.at(i+1) - time.at(i)) >= T) {
      sum += T;
    }
    else {
      sum += (time.at(i+1) - time.at(i));
    }
  } 
  cout << sum + T << endl;
}