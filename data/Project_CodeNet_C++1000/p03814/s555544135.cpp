#include <iostream>

using namespace std;

int main(){
  string s;
  cin >> s;

  int l = 0, r = s.size()-1;
  while(s[l] != 'A')
    l++;
  while(s[r] != 'Z')
    r--;
  
  cout << r-l+1 <<endl;
  
  return 0;
}
