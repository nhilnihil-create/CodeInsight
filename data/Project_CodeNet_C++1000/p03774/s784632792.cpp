#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(N);
  vector<int> C(M), D(M);
  for (int i=0; i<N; i++){
    cin >> A.at(i) >> B.at(i);
  }
  for (int i=0; i<M; i++){
    cin >> C.at(i) >> D.at(i);
  }
  for (int i=0; i<N; i++){
    int diff=400000000;
    int point;
    for (int j=0; j<M; j++){
      int diff_j = abs(A.at(i)-C.at(j))+abs(B.at(i)-D.at(j));
      if (diff_j < diff){
        diff = diff_j;
        point = j+1;
      }
    }
    cout << point << endl;
  }
  
}