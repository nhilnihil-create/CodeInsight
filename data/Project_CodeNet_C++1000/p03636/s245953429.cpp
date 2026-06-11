#include <iostream>
#include <string>
using namespace std;

int main(){
  string s;
  cin >> s;
  int length = s.length();
  string ans = s[0] + std::to_string(length-2) + s[length-1];
  cout << ans << endl;
}