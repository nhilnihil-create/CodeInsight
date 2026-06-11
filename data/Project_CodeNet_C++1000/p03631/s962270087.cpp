#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
  int a;
  cin >> a;
  string s = to_string(a);
  if(s[0] == s[2]) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No"  << endl;
  }

  return 0;
}
