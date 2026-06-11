#include <bits/stdc++.h>
using namespace std;
int main() {
  string A, B, C;
  cin >> A >> B >> C;
  int a = A.size();
  int b = B.size();
  int c = C.size();
  char a2 = A.at(a - 1);
  char b1 = B.at(0);
  char b2 = B.at(b - 1);
  char c1 = C.at(0);
  if (a2 == b1){
    if(b2 == c1){
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  else {
    cout << "NO" << endl;
  }
}
