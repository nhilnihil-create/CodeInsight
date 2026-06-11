#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;

int main() {
  string A, B, C;
  cin >> A >> B >> C;
  int aa=0, bb=0, cc=0;
  char c;
  char win;
  
  c=A[aa];
  aa++;
  
  while (true) {
    if (c=='a') {
      if (aa>A.size()-1) {
        win='A';
        break;
      }
      else {
        c=A[aa];
        aa++;
      }
    }
    else if (c=='b') {
      if (bb>B.size()-1) {
        win='B';
        break;
      }
      else {
        c=B[bb];
        bb++;
      }
    }
    else if (c=='c') {
      if (cc>C.size()-1) {
        win='C';
        break;
      }
      else {
        c=C[cc];
        cc++;
      }
    }
  }
  cout << win << endl;
}