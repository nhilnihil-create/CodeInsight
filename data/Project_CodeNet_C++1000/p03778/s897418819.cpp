#include <iostream>

using namespace std;

int main() {

  int a, b, c;
  cin >> a >> b >> c;
  if(c + a < b){
    cout << abs(c + a - b);
  }else{
    cout << max(0, c - (b + a));
  }
  return 0;
}
