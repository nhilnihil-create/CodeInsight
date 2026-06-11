#include <bits/stdc++.h>
using namespace std;

int main() {
  string A, B, C;
  cin >> A >> B >> C;

  int Asize, Bsize;

  Asize=A.size();
  Bsize=B.size();

  if(A.at(Asize-1)==B.at(0) && B.at(Bsize-1)==C.at(0)){
    cout << "YES";
  }
  else{
    cout << "NO";
  }

return 0;  
}