#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, C, K;
  cin >> N >> C >> K;
  vector<int> A(N);
  for (int &e : A) cin >> e;
  sort(A.begin(), A.end());
  
  int bus = 1;
  int cap = 1;
  int TL = A[0]+K;
  for (int i = 1; i < N; i++) {
    if (A[i] <= TL && cap < C) {
      cap += 1;
    }
    else {
      bus += 1;
      cap = 1;
      TL = A[i] + K;
    }
  }
  cout << bus << endl;
}