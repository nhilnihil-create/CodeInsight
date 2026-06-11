#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string str;
  cin >> str;
  
  reverse(str.begin(), str.end());
  
  bool ans = true;

  while(str.size() != 0) {
    if(str.find("maerd") == 0){
      str = str.erase(0, 5);
    }
    else if(str.find("esare") == 0){
      str = str.erase(0, 5);
    }
    else if(str.find("remaerd") == 0){
      str = str.erase(0, 7);
    }
    else if(str.find("resare") == 0){
      str = str.erase(0, 6);
    }
    else{
      ans = false;
      break;
    }
  }
  
  if(ans){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
 
  
}