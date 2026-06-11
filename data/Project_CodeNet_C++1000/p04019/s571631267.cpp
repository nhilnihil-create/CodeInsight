#include <string>
#include <iostream>
#include <map>
using namespace std;
int main(){
 string s; cin >> s;
  int x=0,y=0;
  map<char,bool> chk;
  for(int i=0;i<s.length();i++){
   /*if(s[i]=='N') y++; 
   if(s[i]=='S') y--;
   if(s[i]=='W') x--;
   if(s[i]=='E') x++;*/
    chk[s[i]]=true;
  }
  string ans;
  if(chk['N']^chk['S'] || chk['W']^chk['E']) ans="No";
  else ans="Yes";
  cout << ans << endl;
}
