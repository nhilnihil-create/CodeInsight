#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string A;
  int N=0, S=0, E=0, W=0;
  cin >> A;
  rep(i, A.size()){
    if(A.at(i)=='N') N=1;
    else if(A.at(i)=='S') S=1;
    else if(A.at(i)=='E') E=1;
    else if(A.at(i)=='W') W=1;
  }
  if(N+S==1 || E+W==1) cout << "No" << endl;
  else cout << "Yes" << endl;
}