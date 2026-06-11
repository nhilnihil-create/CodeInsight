#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,ans=0;
  cin >> N;
  vector<long long>A(N);
  vector<long long>B(N);
  for(int i=0; i<N; i++){
    cin >> A[i] >> B[i];
  }
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
   ans= A[N-1] + B[0];
  cout << ans << endl;
}
