#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  string s;
  cin >> s;
  while(1){
    if(s.substr(0,7)=="dreamer" && s.substr(0,10)!="dreamerase") s.erase(0,7);
    else if(s.substr(0,6)=="eraser" && s.substr(0,9)!="eraserase") s.erase(0,6);
    else if(s.substr(0,5)=="dream") s.erase(0,5);
    else if(s.substr(0,5)=="erase") s.erase(0,5);
    else{
      cout << "NO" << endl;
      break;
    }
    if(s.empty()){
      cout << "YES" << endl;
      break;
    }
  }
  return 0;
}
