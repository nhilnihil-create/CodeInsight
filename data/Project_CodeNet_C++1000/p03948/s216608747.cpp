#include <iostream>
#include <vector>
using namespace std;
int main(){
  int N, T;
  cin >> N >> T;
  vector<int> A(N);
  for(int i = 0; i < N; ++i) cin >> A[i];
  vector<int> M(N), m(N);
  m[0] = A[0];
  for(int i = 1; i < N; ++i) m[i] = min(A[i], m[i-1]);
  M[N-1] = A[N-1];
  for(int i = N-2; i >= 0; --i) M[i] = max(A[i], M[i+1]);
  int D = 0;
  for(int i = 0; i < N; ++i) D = max(D, M[i] - m[i]);
  int x = 0, y = 0;
  for(int i = 0; i < N; ++i){
    if(A[i] - m[i] == D) ++x;
    if(M[i] - A[i] == D) ++y;
  }
  cout << min(x, y) << endl;
  return 0;
}
