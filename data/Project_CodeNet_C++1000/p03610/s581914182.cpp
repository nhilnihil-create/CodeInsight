#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  string s_new="";
  for(int i=0; i < s.size(); i+=2){
    s_new = s_new + s.at(i);
  }
  cout << s_new << endl;
  
}
