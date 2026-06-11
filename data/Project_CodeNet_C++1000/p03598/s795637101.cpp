#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  int K;
  cin >> K;
  int cnt=0;
  vector<int> x(N);
  for (int i=0; i<N; i++) {
    cin >> x[i];
    if (x[i] < abs(K - x[i])) {
      cnt += x[i]*2;
    }
    else {
      cnt += abs(K - x[i])*2;
    }
  }
  cout << cnt << endl;
}