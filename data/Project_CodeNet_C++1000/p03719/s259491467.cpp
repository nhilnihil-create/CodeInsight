#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C;
  cin >> A >> B >> C;
  if(C >= A){
    if(B >= C){
      cout << "Yes" << endl;
    }
    else  {
      cout << "No" << endl;
    }
  }
  else {
    cout << "No" << endl;
  }
}
