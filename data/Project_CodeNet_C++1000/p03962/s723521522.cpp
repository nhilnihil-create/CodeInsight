#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
  int a[3],b=1;
  cin >> a[0] >> a[1] >> a[2];
  sort (a,a+3);
  if (a[0]!=a[1]) b++;
  if (a[1]!=a[2]) b++;
  cout << b;
}