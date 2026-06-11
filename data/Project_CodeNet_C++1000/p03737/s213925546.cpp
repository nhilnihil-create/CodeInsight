#include <iostream>
#include <vector>
using namespace std;

int main(){
  string a,b,c;
  cin >> a >> b >>c;
  a.at(0) -=32;
  b.at(0) -=32;
  c.at(0) -=32;
  cout << a.at(0) << b.at(0) << c.at(0) << endl;
}