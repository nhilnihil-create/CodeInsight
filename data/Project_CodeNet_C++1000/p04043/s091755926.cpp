#include <iostream>

using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  
  bool flag = false;
  
  if (a == 5 && b == 7 && c == 5)
    flag = true;
  if (a == 7 && b == 5 && c == 5)
    flag = true;
  if (a == 5 && b == 5 && c == 7)
    flag = true;
  
  if(flag){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
  
}