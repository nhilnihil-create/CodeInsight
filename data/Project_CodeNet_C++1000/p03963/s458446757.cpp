#include <iostream>
using namespace std;
int main(){
  int i, number, color;
  cin >> number >> color;
  int ans = color;
  for( i=1; i<number; i++ ){
    ans *= color-1;
  }
  cout << ans << endl;
}