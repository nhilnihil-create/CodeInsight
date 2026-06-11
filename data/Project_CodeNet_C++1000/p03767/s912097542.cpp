#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A[3*N];
  for(int i=0; i<3*N; i++) {
    cin >> A[i];
  }
sort(A, A+(3*N));
  long long ans = 0;
   for(int i=(3*N-2); i>=N; i-=2){
        ans += A[i];
    }
    cout << ans << endl;
    return 0;
}