#include <iostream>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(abs(a-b)>abs(a-c))cout << "B";
  else cout << "A";
}
