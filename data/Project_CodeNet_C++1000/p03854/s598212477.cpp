#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  bool judge = true;
  
  if(s.size() < 5){
    judge = false;
  }
  
  while(s.size() > 7){
    if(s.substr(s.size()-5) == "dream" || s.substr(s.size()-5) == "erase"){
      s = s.erase(s.size()-5);
      //cout << s << endl;
      //cout << s.size() << endl;
    }
    else if(s.substr(s.size()-6) == "eraser"){
      s = s.erase(s.size()-6);
      //cout << s << endl;
      //cout << s.size() << endl;
    }
    else if(s.substr(s.size()-7) == "dreamer"){
      s = s.erase(s.size()-7);
    }
    else{
      judge = false;
      break;
    }
  }
  
  if(judge){
    if(s.size() == 5){
      if(s == "dream" || s == "erase"){
        cout << "YES" << endl;
      }
      else{
        cout << "NO" << endl;
      }
    }
    if(s.size() == 6){
      if(s == "eraser"){
        cout << "YES" << endl;
      }
      else{
        cout << "NO" << endl;
      }
    }
    if(s.size() == 7){
      if(s == "dreamer"){
        cout << "YES" << endl;
      }
      else{
        cout << "NO" << endl;
      }
    }
  }
  else{
    cout << "NO" << endl;
  }
}
    