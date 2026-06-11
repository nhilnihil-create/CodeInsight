#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  
  cin >> a >> b;
  
  if(a == b){
      cout << "Draw";
      return 0;
  }
  else if(a == 1){
      cout << "Alice";
      return 0;
  }
  else if(b == 1){
      cout << "Bob";
      return 0;
  }
  else if(a > b){
      cout << "Alice";
      return 0;
  }
  
  else{
      cout << "Bob";
      return 0;
  }
  return 0;
}
