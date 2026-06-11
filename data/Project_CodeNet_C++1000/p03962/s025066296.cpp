#include <iostream>

using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  
  int count = 3;
  if(a == b || b == c || c == a) count--;
  if(a == b && b == c) count--;
  
  cout << count << endl;
}