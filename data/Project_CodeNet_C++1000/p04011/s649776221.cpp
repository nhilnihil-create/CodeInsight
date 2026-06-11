#include <iostream>
using namespace std;

int main(){
  int a, b,c,d;
  cin >> a >> b >> c >>d;
  cout << min(a,b) * c + max(a-b,0) * d;
}
