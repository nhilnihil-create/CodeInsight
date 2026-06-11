#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int sec = 0;
  if(a < c){
    if(b <= c) {
      sec = 0;
    } else {
      sec = min(b,d) - c;
    }
  } else {
    if (d <= a) {
      sec = 0;
    } else {
      sec = min(b,d) -a;
    }
  }
  cout << sec << endl;

  return 0;
}
