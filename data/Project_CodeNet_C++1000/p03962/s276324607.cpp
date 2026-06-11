#include <iostream>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  
  int result = 0;
  if(a == b){
    if(a == c){
      result = 1;
    }else{
      result = 2;
    }
  }else{
    if(a == c || b == c){
      result = 2;
    }else{
      result = 3;
    }
  }

  cout << result;
  return 0;
}