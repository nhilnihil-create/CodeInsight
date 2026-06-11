#include <iostream>

using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  a += b;
  if(a>23) a-=24;
  cout << a;
}
