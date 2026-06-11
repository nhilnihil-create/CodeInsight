#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
  
  long long x, y;
  cin >> x >> y;
  
  long long dif = abs(x-y);
  
  if (dif <= 1) cout << "Brown" << endl;
  else cout << "Alice" << endl;
    
}
