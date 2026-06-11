#include <iostream>

using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  if (b == 1) b = 14;
  if (a == 1) a = 14;
  if (a > b) cout << "Alice\n";
  else if (b > a) cout << "Bob\n";
  else cout << "Draw\n";
  return 0;
}