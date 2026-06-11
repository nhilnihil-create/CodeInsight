#include<iostream>
#include<string>
using namespace std;
int main(void){
  string a, b, c;
  cin >> a >> b >> c;
  char d, e, f;
  d = a[0] - 32;
  e = b[0] - 32;
  f = c[0] - 32;
  cout << d << e << f <<endl;
  return 0;
}