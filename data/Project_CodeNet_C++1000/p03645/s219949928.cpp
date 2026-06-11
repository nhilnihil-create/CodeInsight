#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin >> N >> M;
  vector<int>A(M);
  vector<int>B(M);
  vector<int>a(N,0);
  vector<int>b(N,0);
  
  for (int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
    if (A.at(i) == 1){
      a.at(B.at(i)-1)++;
    }
    else if (A.at(i) == N){
      b.at(B.at(i)-1)++;
    }
    else if (B.at(i) == N){
      b.at(A.at(i)-1)++;
    }
  }
  
  for (int i = 0; i < N; i++) {
    if (a.at(i) == 1 && b.at(i) == 1){
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}
  