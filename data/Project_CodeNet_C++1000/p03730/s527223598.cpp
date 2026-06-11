#include <iostream>

using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >>c ;
  bool flg = false;
  for(int i = 0; i < 100; i++) {
    int tmp = a*i;
    if(tmp%b == c) {
      flg = true;
      break;
    }
  }
  if(flg) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
