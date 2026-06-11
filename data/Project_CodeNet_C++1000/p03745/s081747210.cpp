#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A;
  
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    if (i > 0 && A[A.size()-1] == x) continue;
    A.push_back(x);
  }
  
  int s = A.size();
  int F = 0;
  for (int i = 1; i < s-1; i++) {
    if (signbit(A[i-1]-A[i]) ^ signbit(A[i]-A[i+1])) {
      F += 1;
      i += 1;
    }
  }
  
  cout << F+1 << endl;
}