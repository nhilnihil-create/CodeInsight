#include <iostream>
using namespace std;

int main() {
  long long N;
  cin >> N;
  long long A[N], B[N];
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
  long long count = 0;
  
  for (int i = N - 1; i >= 0; i--){
    if ((A[i] + count) % B[i] != 0) count += B[i] - (A[i] + count) % B[i];
  }
  
  cout << count << endl;
}