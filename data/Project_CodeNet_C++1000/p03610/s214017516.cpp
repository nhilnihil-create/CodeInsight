#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  int i;
  for(i=0;i<s.size();i++){
    if((i+1)%2==1) cout << s[i];
  }
  cout << "\n";
  return 0;
}