#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  bool ans = 1;
  while(true){
    int size = s.size();
    if(s.substr(size-5) == "erase"){
      s.erase(size-5);
    }
    else if(s.substr(size-5) == "dream"){
      s.erase(size-5);
    }
    else if(s.substr(size-6) == "eraser"){
      s.erase(size-6);
    }
    else if(s.substr(size-7) == "dreamer"){
      s.erase(size-7);
    }
    else{
      ans = 0;
        break;
    }
    if(s.empty() == 1){
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