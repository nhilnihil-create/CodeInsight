#include <iostream>
using namespace std;

int main(){
  long long X;
  cin >> X;
  long long ng = 0, ok = X;
  while(ok-ng > 1){
    long long mid = (ok+ng)/2;
    long long Y = (mid+1)*mid/2;
    if(Y >= X) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}
