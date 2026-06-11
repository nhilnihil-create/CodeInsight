#include <iostream>


using namespace std;

int main(){
  int w, a, b;
  cin >> w >> a >> b;
  int ret = 0;
  if(a <= b) {
    ret = max(0, (b-(a+w)));
  } else {
    ret = max(0, (a-(b+w)));
  }
  cout << ret << endl;
  return 0;
} 
