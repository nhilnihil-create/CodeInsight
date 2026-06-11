#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  cin >> A >> B;
  if(0<A){
    cout << "Positive" << endl;
  }
  else if(A<=0 && 0<=B){
    cout << "Zero" << endl;
  }
  else{
    int C=B-A+1;
    if(C%2==0){
      cout << "Positive" << endl;
    }
    else{
      cout << "Negative" << endl;
    }
  }
}