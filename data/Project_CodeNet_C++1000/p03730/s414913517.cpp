#include <iostream>
using namespace std;

int main(){
  int A, B, C;
  cin >> A >> B >> C;
  int a = A;
  bool can = true;
  while(true){
    if(a%B==C){
      break;
    }
    if(a!=A && a%B==A%B){
      can = false;
      break;
    }
    a += A;
  }
  if(can){
    cout << "YES";
  }else{
    cout << "NO";
  }
  return 0;
}