#include <bits/stdc++.h>
#define rep(i,a,n) for (int i =a; i<n; i++)
using namespace std;

int main() {
  string A,B; cin >> A >> B;
  int sizeA = A.size(), sizeB = B.size();
  if (sizeA > sizeB) {
    cout << "GREATER" << endl; return 0;
  } else if (sizeA < sizeB) {
    cout << "LESS" << endl; return 0;
  } else {
    rep(i,0,sizeA) {
      if (A[i] == B[i]) continue;
      if ((int)(A[i] - '0') > (int)(B[i] - '0')) {
        cout << "GREATER" << endl; return 0;
      } else {
        cout << "LESS" << endl; return 0;
      }
    }
    cout << "EQUAL" << endl;
  }            
}