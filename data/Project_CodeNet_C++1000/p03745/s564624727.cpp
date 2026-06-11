#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  int ans = 0;
  for (int i = 0; i < N; i++){
    while (i+1 <= N && A[i] == A[i+1]) i++;

    if (A[i] > A[i+1]) {
      while (i+1 <= N && A[i] >= A[i+1]) i++;
    } else {
      while (i+1 <= N && A[i] <= A[i+1]) i++;
    }
    ans++;
  }
  cout << ans << endl;   
}