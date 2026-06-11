#include <iostream>
#include <string>
using namespace std;
int main(){
  string s;
  cin >> s;
  cout << s.rfind('Z') - s.find('A') + 1;
  return 0;
}