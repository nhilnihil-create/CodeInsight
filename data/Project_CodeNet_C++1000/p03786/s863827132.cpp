#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

int main(){
  int N;
  cin>>N;
  vector<ll> A(N),R(N);
  for(int i(0);i<N;i++){
    cin>>A[i];
  }
  sort(A.rbegin(),A.rend());
  R[N-1] = A[N-1];
  for(int i(N-2);i>=0;i--){
    R[i] = R[i+1] + A[i];
  }
  // for(int i(0);i<N;i++){
  //   cout << A[i] << " ";
  // }
  // cout << endl;
  // for(int i(0);i<N;i++){
  //   cout << R[i] << " ";
  // }
  // cout << endl;
  for(int i(0);i<N-1;i++){
    //cout << A[i] << " " << R[i+1] << endl;
    if(A[i] > R[i+1]*2){
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << N << endl;
  return 0;
}
