#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N), B(N);
  for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];

  vector<long long> C(N+1, 0); // C[N] = 0 を番兵としておく
  for (int i = N-1; i >= 0; --i) {
      A[i] += C[i+1]; // とりあえず前回分を足しておく
      long long amari = A[i] % B[i];
      long long need = 0;
      if (amari != 0) need = B[i] - amari; // 追加で必要な分
      C[i] = C[i+1] + need;
  }
  cout << C[0] << endl;
}