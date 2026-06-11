#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  vector<char> s;
  while(true){
    char x; cin >> x;
    if(cin.eof()) break;
    s.push_back(x);
  }
  
  bool turn = true;
  while(true){
    if(s.size() <= 2){
      cout << (turn ? "Second" : "First") << endl;
      return 0;
    }
    bool flag = false;
    for(int i=1; i<s.size()-1; ++i){
      if(s[i-1] != s[i+1]){
        s.erase(s.begin() + i);
        turn = !(turn);
        flag = true;
        break;
      }
    }
    if(!flag){
      cout << (turn ? "Second" : "First") << endl;
      return 0;
    }
  }
  
  return 0;
}