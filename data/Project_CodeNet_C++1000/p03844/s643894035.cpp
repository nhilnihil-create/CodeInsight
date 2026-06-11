#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  char c;
  
  cin >> a >>  c >> b;
  
  if(c == '+'){
    
    cout << a+b;
    return 0;
  }
  else{
      cout << a-b;
  }
  return 0;
}