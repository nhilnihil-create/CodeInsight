#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, a, b;
  cin >> N >> M;
  vector<int> A(N);
  for(int i = 0; i < M; i++){
  cin >> a >> b;
    for(int i = 0; i < N; i++){
      int s = i + 1;
      if(a == s){
        A.at(i) += 1;
      }
      if(b == s){
        A.at(i) += 1;
      }
    }
  }
  for(int i = 0; i < N; i++){
  cout << A.at(i) << endl;
  }
}
