#include <iostream>
 
int main() {
  int five = 0;
  int seven = 0;
  
  using namespace std;
  int i;
  cin >> i;
  if (i == 5) ++five; else if (i == 7) ++seven;
  cin >> i;
  if (i == 5) ++five; else if (i == 7) ++seven;
  cin >> i;
  if (i == 5) ++five; else if (i == 7) ++seven;
  cout << (five == 2 && seven == 1 ? "YES" : "NO");
}