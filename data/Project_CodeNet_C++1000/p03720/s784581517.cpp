#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int>A(2*M);
  for(int i=0; i<2*M; i++)cin >> A.at(i);
  
  vector<int>ANS(N);
  for(int i=0; i<2*M; i++){
    ANS.at(A.at(i)-1) ++;
  }
  
  for(int i=0; i<N; i++)cout << ANS.at(i) <<endl;
}
