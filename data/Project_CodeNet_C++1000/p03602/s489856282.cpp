#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector< vector<long long int> > A(N,vector<long long int>(N));
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      cin >> A[i][j];
    }
  }
  long long int t = 0;
  
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      for(int k = 0; k < N; ++k){
        if(A[i][j] > A[i][k] + A[k][j]){
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < i; ++j){
      t += A[i][j];
      for(int k = 0; k < N; ++k){
        if(k == i || k == j) continue;
        if(A[i][j] == A[i][k] + A[k][j]){
          t -= A[i][j];
          break;
        }
      }
    }
  }
  cout << t << endl;
  return 0;
}
