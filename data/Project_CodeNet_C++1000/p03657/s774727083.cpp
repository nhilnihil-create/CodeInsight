#include <iostream>
using namespace std;
 
int main() {
 int x, y;
 cin >> x >> y;
 int z = x + y;
 if (z % 3 == 0 || x % 3 == 0 || y % 3 == 0)
   cout << "Possible";
 else
   cout << "Impossible";
}