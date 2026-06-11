#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int ans;
  while(true){
    s.pop_back();
    if(s.substr(0,s.size()/2) == s.substr(s.size()/2,s.size()/2) && s.size() % 2 == 0){
      cout << s.size() << endl;
      return 0;
    }
  }
}