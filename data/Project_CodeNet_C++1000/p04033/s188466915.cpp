#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  if(a<0 && b<0 && ((abs(a-b)+1)%2 == 1)){
   cout << "Negative" << endl;
    return 0;
  }
  else if(a<0 && b<0){
   cout << "Positive" << endl;
    return 0;
  }
  else if(a>0 && b>0){
    cout << "Positive" << endl;
    return 0;
  }
 else {
   cout << "Zero" << endl;
 }
}
