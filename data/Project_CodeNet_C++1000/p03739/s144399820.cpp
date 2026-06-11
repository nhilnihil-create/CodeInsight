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
  long sum1 = 0, hosei1 = 0;
  for (long i = 0; i < N; i++) {
    if (i % 2 == 0) {
      if (R.at(i) + hosei1 > -1) {
        long tmp = (R.at(i) + hosei1) - -1;
        hosei1 -= tmp;
        sum1 += tmp;
      }
    } else {
      if (R.at(i) + hosei1 < 1) {
        long tmp = 1 - (R.at(i) + hosei1);
        hosei1 += tmp;
        sum1 += tmp;
      }
    }
  }
  long sum2 = 0, hosei2 = 0;
  for (long i = 0; i < N; i++) {
    if (i % 2 == 0) {
      if (R.at(i) + hosei2 < 1) {
        long tmp = 1 - (R.at(i) + hosei2);
        hosei2 += tmp;
        sum2 += tmp;
      }
    } else {
      if (R.at(i) + hosei2 > -1) {
        long tmp = (R.at(i) + hosei2) - -1;
        hosei2 -= tmp;
        sum2 += tmp;
      }
    }
  }
  cout << min(sum1, sum2) << "\n";
}