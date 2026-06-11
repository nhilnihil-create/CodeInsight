#include<bits/stdc++.h>
using namespace std;
int main() {
  int A, B; cin >> A >> B;
  string s;
  if(A == B) s = "Draw";
  else if(A < B) {
    if(A == 1) s = "Alice";
    else s = "Bob";
  } else {
    if(B == 1) s = "Bob";
    else s = "Alice";
  }
  cout << s << endl;
}