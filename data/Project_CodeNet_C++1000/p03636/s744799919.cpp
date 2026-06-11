#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  int x = s.size()-2;
  cout << s[0] << x << s[s.size()-1] << "\n";
  return 0;
}