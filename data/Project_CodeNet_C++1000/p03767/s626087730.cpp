#include <iostream>
#include <algorithm>
using namespace std;

int main () {
  long long N;
  cin >> N;
  long long A[3 * N];
  for (long long i = 0; i < 3 * N; i++) cin >> A[i];
  sort(A, A + 3 * N);
  long long res = 0;
  for (long long i = N; i < 3 * N; i++){
    if ((i - N) % 2 == 0) res += A[i];
  }
  cout << res << endl;
}