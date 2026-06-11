#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  if(N == 1) {
    cout << 1 << endl;
  } else {
    int temp = 2;
    while(temp <= N) temp <<= 1;
    cout << (temp >> 1) << endl;
  }
  return 0;
}
