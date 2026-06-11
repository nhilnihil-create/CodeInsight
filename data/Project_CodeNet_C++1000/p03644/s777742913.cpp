#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int a = 1;
  while(a <= n) {
    if(a*2 <= n) {
      a = a*2;
    } else {
      break;
    }
  }
  cout << a << endl;
  return 0;
}
