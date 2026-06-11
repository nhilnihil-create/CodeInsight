#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int &e : A) {
    cin >> e;
  }
  
  int pos = 0;
  for (int i = 0; i < N; i++) {
    if(A[A[i]-1] == i+1) {
      pos += 1;
    }
  }
  
  cout << pos/2 << endl;
}