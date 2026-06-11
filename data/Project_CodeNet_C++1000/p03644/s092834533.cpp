#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int temp = 1;
  while(temp <= N) temp <<= 1;
  cout << (temp >> 1) << endl;
  
  return 0;
}
