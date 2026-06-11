#include <bits/stdc++.h>
#include <math.h>
#include <ctype.h>
using namespace std;
int main(){

bool equal = true;
string A, B;
cin >> A >> B;

if (A.size() > B.size()){
  cout << "GREATER" << endl;
  equal = false;
}
else if(B.size() > A.size()){
  cout << "LESS" << endl;
  equal = false;
}
else{
  for (int i = 0; i < A.size(); i++){
    if(A.at(i) == B.at(i)){
      continue;
    }
    else if(A.at(i) > B.at(i)){
      cout << "GREATER" << endl;
      equal = false;
      break;
    }
    else{
      cout << "LESS" << endl;
      equal = false;
      break;
    }
  }
}

if(equal == true){
  cout << "EQUAL" << endl;
}

return 0;
}