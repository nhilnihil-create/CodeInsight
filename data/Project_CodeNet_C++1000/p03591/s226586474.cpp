#include <iostream>
#include <string>

using namespace std;

int main(void){
  string str;
  
  cin >> str;
  
  if(str.length() < 4) cout << "No" << endl;
  else if(str.substr(0, 4) != "YAKI") cout << "No" << endl;
  else cout << "Yes" << endl;
  
  return 0;
}