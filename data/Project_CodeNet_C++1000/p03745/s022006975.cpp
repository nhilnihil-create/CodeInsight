#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  int cnt = 0;
  vector<int> A(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
  }

  for(int i = 0; i < N; i++){
    // same を抜ける
    while (i+1 < N && A[i] == A[i+1]) ++i;

    // up
    if (i+1 < N && A[i] < A[i+1]) {
        while (i+1 < N && A[i] <= A[i+1]) ++i;
    }
    // down
    else if (i+1 < N && A[i] > A[i+1]) {
        while (i+1 < N && A[i] >= A[i+1]) ++i;
    }
    cnt++;
  }
  cout << cnt << endl;
}
