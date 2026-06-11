#include<iostream>
using namespace std;

int main(){
  int a, b, c, d, e, f;
  cin >> a >> b >> c;
  d = a + b;
  e = a + c;
  f = b + c;
  cout << min(e, min(d, f));
}