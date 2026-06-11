#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, A[100000];
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);
  reverse(A, A + N);

  int pos = 0;
  for(int i = 0; i < N; i++) {
    if(i + 1 <= A[i]) {
      pos = i;
    } else {
      break;
    }
  }
  int length = 0;
  for(int i = pos; i + 1 < N; i++) {
    if(pos < A[i + 1]) ++length;
  }
  if(length % 2 == 0 && (A[pos] - pos + 1) % 2 == 0) cout << "Second\n";
  else cout << "First" << endl;
}