#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int N, M, A[300010];
  cin >> N; M = 3 * N;
  for (int i = 0; i < M; i++) cin >> A[i];
  sort(A, A+M);
  long sum = 0;
  int j = M-2;
  for (int i = 0; i < N; i++) {
    sum += A[j]; j -= 2;
  }
  cout << sum << endl;
}