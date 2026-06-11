#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin >> N;
  vector<long> A(N);
  for (long i = 0; i < N; i++) cin >> A.at(i);
  vector<long> R(N);
  R.at(0) = A.at(0);
  for (long i = 1; i < N; i++) {
    R.at(i) = R.at(i - 1) + A.at(i);
  }
  long sum = 0, cor = 0;
  for (long i = 0; i < N; i++) {
    if (i % 2 == 0) {
      if (R.at(i) + cor > -1) {
        long tmp = (R.at(i) + cor) - -1;
        cor -= tmp;
        sum += tmp;
      }
    } else {
      if (R.at(i) + cor < 1) {
        long tmp = 1 - (R.at(i) + cor);
        cor += tmp;
        sum += tmp;
      }
    }
  }
  long ans = sum;
  sum = 0, cor = 0;
  for (long i = 0; i < N; i++) {
    if (i % 2 == 1) {
      if (R.at(i) + cor > -1) {
        long tmp = (R.at(i) + cor) - -1;
        cor -= tmp;
        sum += tmp;
      }
    } else {
      if (R.at(i) + cor < 1) {
        long tmp = 1 - (R.at(i) + cor);
        cor += tmp;
        sum += tmp;
      }
    }
  }
  cout << min(ans, sum) << "\n";
}