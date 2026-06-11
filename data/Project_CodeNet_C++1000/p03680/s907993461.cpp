#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, k = 0;
  cin >> N;
  vector<int> A(N);

  for(int i=0; i<N; i++) {
    cin >> A.at(i);
  }
  
  for(int i=0; i<N; i++) {
    if(i==1) break;
    k++;
    if(k==N) {
      k=-1;
      break;
    }
    i = A.at(i)-2;

  }
  cout << k << endl;
  
}