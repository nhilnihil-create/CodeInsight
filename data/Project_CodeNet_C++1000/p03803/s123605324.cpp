#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if(a == b) cout << "Draw" << endl;
  else if( a == 13 && b == 1) cout << "Bob" << endl;
  else if( b == 13 && a == 1) cout << "Alice" << endl;
  else if( a < b) cout << "Bob" << endl;
  else cout << "Alice" << endl;

  
  return 0;

}