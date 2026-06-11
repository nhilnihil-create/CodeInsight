#include <iostream>
using namespace std;
int main(void){
  int n;
  cin >> n;
  
  int p = 0;
  int t = 1;
  
  while(1){
    p += t;
    if(p >= n)
      break;
    t++;
  }
  
  cout << t << endl;
  
  return 0;
}

    