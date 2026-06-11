#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  cin>>s;
  if(s.size() == 2){
    if(s[0] == s[1])puts("1 2");
    else puts("-1 -1");
  }
  else {
    for(int l = 0; l + 2 < s.size(); ++l){
      int r = l + 2;
      if(s[l] == s[l + 1] || s[l] == s[l + 2] || s[l + 1] == s[l + 2]){
        cout<<l + 1 <<" " << l+3<<endl;
        return 0;
      }
    }
    puts("-1 -1");
  }
}