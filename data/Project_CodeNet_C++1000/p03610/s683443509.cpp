#include <iostream>
#include <string>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  string R=""; 
  for(int i = 0;i<s.size();i++){
    if((i + 1)% 2 !=0) R+=s[i];
  }
  cout << R << endl;
}