#include <bits/stdc++.h>
using namespace std;

int main() {
  string A, B, C;
  cin >> A >> B >> C;

  if(A.back()==B.at(0) && B.back()==C.at(0)){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }

return 0;  
}