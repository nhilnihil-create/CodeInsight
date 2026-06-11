#include <bits/stdc++.h>
using namespace std;

int main() {
  string A,B,C;
  cin >> A >> B >> C;
  int a = A.size(), b = B.size();
  
  if(A[a-1] == B[0] && B[b-1] == C[0]) {
    cout << "YES" << endl;
  }
  else cout << "NO" << endl;
}