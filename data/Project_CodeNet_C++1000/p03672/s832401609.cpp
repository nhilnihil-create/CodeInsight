#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  bool ok=false;
  int stlength=0;
  for(int i=2,l=s.size();i<l;i+=2){
    string s2="";
    for(int j=0;j<l-i;j++)
      s2+=s.at(j);
    ok=true;
    for(int j=0;j<s2.size()/2;j++){
      if(s2.at(j)!=s2.at(j+s2.size()/2)){
        ok=false;
        break;
      }
      stlength=s2.size();
    }
    if(ok)
     break; 
  }
  cout << stlength << endl;
}
 