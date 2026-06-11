#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  vector<long long> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(),A.end());
  
  long long ans = 0, sum = 0;

  for(int i = 0; i < N; i++){
    if(sum * 2 < A[i]){
      ans = 0;
    }
    sum += A[i];
    ++ans;
  }
  cout << ans << endl;
  return 0;
}




