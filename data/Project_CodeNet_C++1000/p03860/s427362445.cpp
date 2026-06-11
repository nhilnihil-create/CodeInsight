#include <iostream>
using namespace std;

int main(){
  string s;
  getline(cin, s);
  string ans;
  for(int i = 0; i < s.size(); i++){
     if(i == 0) ans += s.at(i);
     else if(s.at(i - 1) == ' ') ans += s.at(i);
  }
  cout << ans << endl;
}