#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>
using namespace std;

int main(){
  int w, a, b;
  cin >> w >> a >> b;
  if(a + w >= b && a + w <= b + w){
    cout << 0 << endl;
  }
  else if(a >= b && a <= b + w){
    cout << 0 << endl;
  }
  else{
    if(a + w < b){
      cout << b - (a + w) << endl;
    }
    if(a > b + w){
      cout << a - (b + w) << endl;
    }
  }
}