#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  long long N, A[100001], B[100001], maxA = 0, key = 0;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> A[i] >> B[i];
    if(A[i] >= maxA){
      maxA = A[i];
      key = i;
    }
  }
  cout << maxA + B[key] << endl;
  return 0;
}
