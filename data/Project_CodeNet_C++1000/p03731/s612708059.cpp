#include <bits/stdc++.h>
using namespace std;

int main() {

  long long N, T;
  cin >> N >> T;

  vector<long long> t(N);
  for (int i = 0; i < N; i++) {
    cin >> t[i];
  }

  long long answer = T;

  for (int i = 1; i < N; i++) {
    if (t[i] - t[i-1] < T) {
      answer += t[i] - t[i-1];
    } else {
      answer += T;
    }
  }
  
  cout << answer << endl;

  return 0;

}