#include <bits/stdc++.h>
using namespace std;

int main() {
 int A,B,C,D;
  cin >> A >> B >> C >> D;
  if(B >= A){
cout << C * A << endl;
  }
  else{
    cout << B * C + (A - B) * D << endl;
  }

}
