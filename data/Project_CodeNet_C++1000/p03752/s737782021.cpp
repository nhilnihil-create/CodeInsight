#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;cin >> N >> K;
  vector<long> A(N);
  for (int i=0;i<N;i++) {
    cin >> A.at(i);
  }
  long min_cost = 100000000000;
  for (int bit=0;bit<(1<<(N-1));bit++) {
    vector<long> B = A;
    long max_h=B.at(0);
    long cost=0;
    int color=1;
    for (int i=0;i<N-1;i++) {
      if ((bit>>i) & 1) {
        if (max_h >= B.at(i+1)) {
          cost += (max_h+1L-B.at(i+1));
          B.at(i+1) = max_h + 1L;
        }
        color++;
      }
      max_h = max(max_h,B.at(i+1));
    }
    if (color>=K) min_cost=min(cost,min_cost);
  }
  cout << min_cost << endl;
}