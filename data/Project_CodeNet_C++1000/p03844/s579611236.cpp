#include <iostream>
#include <string>

using namespace std;

int main(){
  int a,b,y;
  string x;
  cin >> a >> x >> b;
  if(x == "+") y = a + b;
  else if ( x == "-") y = a - b;
  cout << y;
  return 0;
}
