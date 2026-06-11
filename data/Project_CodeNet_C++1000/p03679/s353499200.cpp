#include <iostream>
using namespace std;
int main(){
  int X,A,B;
  cin >> X >> A >> B;
  if(A >= B){
    cout << "delicious";
  }
  else if(A+X >= B){
    cout << "safe";
  }else{
    cout << "dangerous";
  }
  return 0;
}