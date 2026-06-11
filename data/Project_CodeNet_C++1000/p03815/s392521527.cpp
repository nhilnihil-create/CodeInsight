#include <iostream>

using namespace std;

int main(){
  unsigned long x;
  cin >> x;

  unsigned long rot = 0UL;
  rot = (x/11UL)*2UL;
  if(0UL < x%11UL){
    if(x%11UL <= 6UL) {
      rot += 1UL;
    } else {
      rot += 2UL;
    }
  }
  cout << rot << endl;
  return 0;
}

