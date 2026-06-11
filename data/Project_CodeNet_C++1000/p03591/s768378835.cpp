#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string A;
  cin >> A;
  
  int size = A.size();
  if(size < 4) {
    cout << "No" << endl;
  }
  else if((A.at(0) == 'Y' && A.at(1) == 'A') && (A.at(2) == 'K' && A.at(3) == 'I')) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
