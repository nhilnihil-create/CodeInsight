#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int tot = a+b+c;
  cout << tot - max({a,b,c});
  
}