#include <bits/stdc++.h>
using namespace std;

int main() {
  string A,B;
  cin >> A >> B;
  
  if(A == "H" && B == "H"){
    cout << "H" << endl;
}

  if(A == "H" && B == "D"){
    cout << "D" << endl;
}
  
 if(A == "D" && B == "H"){
    cout << "D" << endl;
}
  
  if(A == "D" && B == "D"){
    cout << "H" << endl;
}
}