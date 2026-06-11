#include <iostream>

typedef unsigned long ULONG;

using namespace std;
int main(){
  ULONG a, b, x;
  cin >> a >> b >> x;

  ULONG ret = b/x;
  if(a != 0) {
    ret -= (a-1UL)/x;
  } else {
    ret++;
  }
  cout << ret << endl;
  return 0;
}
