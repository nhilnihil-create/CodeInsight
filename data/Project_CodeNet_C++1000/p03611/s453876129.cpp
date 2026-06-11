#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  if(N == 1){
    int A;
    cin >> A;
    cout << 1 << endl;
    return 0;
  }
  if(N == 2){
    int A,B;
    cin >> A >> B;
    if(abs(A-B) < 2){
      cout << 2 << endl;
      return 0;
    }
    cout << 1 << endl;
    return 0;
  }
  vector<int>vec(N,0);
  for(int i=0; i<N; i++){
    int M;
    cin >> M;
    if(M-1 >= 0 && M-1 <= N){
      vec[M-1]++;
    }
    vec[M]++;
    if(M+1 <= N){
      vec[M+1]++;
    }
  }
  sort(vec.begin(),vec.end());
  cout << vec[N-1] << endl;
}
