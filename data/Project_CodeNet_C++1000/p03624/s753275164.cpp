#include<bits/stdc++.h>
using namespace std;
 
int main(){
  string s;
  cin >> s;
  for(char a = 'a'; a<='z'; a++){
    bool b = false;
    for(int i = 0; i<s.size(); i++){
      if(s.at(i) == a){
        b = true;
        break;
      }
    }
    if(!b){
      cout << a << endl;
      return 0;
      break;
    }
  }
    cout << "None" << endl;
}