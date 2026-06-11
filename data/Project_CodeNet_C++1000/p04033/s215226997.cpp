#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  cin >> A >> B;
  int C=B-A+1;
  if(A<=0 && 0<=B){
    cout << "Zero" << endl;
  }
  else if(0<A || C%2==0){
    cout << "Positive" << endl;
  }
  else{
    cout << "Negative" << endl;
  }
}   