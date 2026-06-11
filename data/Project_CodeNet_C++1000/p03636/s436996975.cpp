#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int W,B;
  char  A,C;
  W=S.size();
  A=S[0];B=W-2;C=S[W-1];
  cout << A << B << C << endl;
}