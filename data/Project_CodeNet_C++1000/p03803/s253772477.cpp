#include <iostream>
using namespace std;
int a,b;
int main() {
  cin >> a >> b;
  if (a == b)
  {
      cout << "Draw" << endl;
  }
  else if(a == 1){
      cout << "Alice" << endl;
  }
  else if(b == 1){
      cout << "Bob" << endl;
  }
  else if(a > b){
      cout << "Alice" << endl;
  }
  else if(b > a){
      cout << "Bob" << endl;
  }
  return 0;
}