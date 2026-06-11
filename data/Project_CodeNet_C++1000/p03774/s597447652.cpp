#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,M;
  cin >> N >> M;
  vector<int>a(N);
  vector<int>b(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i) >> b.at(i);
  }
  vector<int>c(M);
  vector<int>d(M);
  for (int i = 0; i < M; i++) {
    cin >> c.at(i) >> d.at(i);
  }
  
  vector<int>A(M);
  for (int j = 0; j < N; j++) {
    int MIN = 1000000000; 
    int B = 1;
    for (int i = 0; i < M; i++) {
      A.at(i) = abs(a.at(j)-c.at(i)) + abs(b.at(j)-d.at(i));
      if (A.at(i) < MIN){
        MIN = A.at(i);
        B = i+1;
      }
    }
    cout << B << endl;
  }
}
    
  