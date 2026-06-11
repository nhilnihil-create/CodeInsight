#include<bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin >> s >> t;
  if(s.size() > t.size()) { cout << "GREATER" << endl; return 0; }
  else if(s.size() < t.size()) { cout << "LESS" << endl; return 0; }
  for(int i = 0; i < s.size(); i++){
    if(s[i] > t[i]){
      cout << "GREATER" << endl;
      return 0;
    }else if(s[i] < t[i]){
      cout << "LESS" << endl;
      return 0;
    }
  }
  cout << "EQUAL" << endl;
  return 0;
}