#include <iostream>
using namespace std;
int main(){
  string a,b,c;
  cin >> a >> b >> c;
  char x = 'A' - 'a';
  cout << (char)(a[0]+x) << (char)(b[0]+x) << (char)(c[0]+x) << "\n";
  return 0;
}