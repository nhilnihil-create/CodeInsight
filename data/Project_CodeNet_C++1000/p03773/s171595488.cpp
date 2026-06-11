#include <iostream>

using namespace std;

int main(){
  int a, b;
  cin  >> a >> b;
  if(24 <= a+b) {
    cout << a+b-24 << endl;
  } else {
    cout << a+b << endl;
  }
  return 0;
}
