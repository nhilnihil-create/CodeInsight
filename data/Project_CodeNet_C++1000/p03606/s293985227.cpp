#include <iostream>
using namespace std;
int main(void){
    // Your code here!
  int i;
  cin >> i;
  int j;
  int k=0;
  for(j=0;j<i;j++){
    int a;
    int b;
    cin >> a >> b;
    k = k + b - a + 1;
  }
  cout << k;
}
