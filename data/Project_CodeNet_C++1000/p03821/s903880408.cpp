#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int64_t i=0; i<(int64_t)(n); i++)
#define all(v) v.begin(), v.end()
//4
int main(){
  
  int N;
  cin >> N;
  vector<int64_t> A(N), B(N);
  rep(i, N) cin >> A[i] >> B[i];
  
  int64_t cnt=0;
  rep(i, N){
    if((A[N-1-i]+cnt)%B[N-1-i]==0) continue;
    cnt += B[N-1-i]-((A[N-1-i]+cnt)%B[N-1-i]);
  }
  
  cout << cnt << endl;
  
}