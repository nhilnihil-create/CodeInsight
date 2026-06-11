#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  int n;cin>>n;
  vector<long long>A(n);
  vector<long long>B(n+2);
  for(int i = 0; n > i; i++){
    cin>>A[i];
  }
  sort(A.begin(),A.end());
  B[0] = 0;
  for(int i = 0; n > i; i++){
    B[i+1] = B[i]+A[i];
  }
  B[n+1] = 0;
  for(int i = n-1; 0 < i; i--){
    if(B[i]*2 < A[i]){
      cout << n-i << endl;
      return 0;
    }
  }
  cout << n << endl;
}
