#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  char a, b;
  cin >> a >> b;
  if(a=='H') cout << b;
  else cout << (b=='H' ? 'D' : 'H');
}