#include <iostream>
#include <vector>
using namespace std;

uint getResult(const vector<uint> &A, const vector<uint> &B, const uint N){
  uint maxIndex = 0;
  for(uint i = 1; i < N; i++){
    if(A[maxIndex] < A[i]) maxIndex = i;
  }
  return A[maxIndex] + B[maxIndex];
}

int main(){
  uint N;
  cin >> N;
  
  vector<uint> A(N), B(N);
  for(uint i = 0; i < N; i++){
    cin >> A[i] >> B[i];
  }
  
  uint result = getResult(A, B, N);
  
  cout << result;
  return 0;
}