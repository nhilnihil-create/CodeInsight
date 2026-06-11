#include <iostream>

using namespace std;

int main(void){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if(a * b <= c * d){
    cout << c * d << endl;
  }else{
    cout << a * b << endl;
  }
  return 0;
}