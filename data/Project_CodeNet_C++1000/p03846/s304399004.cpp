#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  int A[N]; for (int i =0; i<N; i++) cin >> A[i];
  
  sort(A,A+N);
  bool check = false;
  
  for (int i =0; i<N; i++) {
    if (N % 2 ==0 && i % 2 ==0 && A[i] != i + 1) check = true;
    if (N % 2 ==0 && i % 2 ==1 && A[i] != i) check = true;
    if (N % 2 ==1 && i % 2 ==0 && A[i] != i) check = true;
    if (N % 2 ==1 && i % 2 ==1 && A[i] != i + 1) check = true;
  }
  
  long ans =1;
  for (int i =0; i<N/2; i++) {
    ans *= 2; ans %= 1000000007;
  }

  if (check) cout << 0 << endl;
  else  cout << ans << endl;
  
}