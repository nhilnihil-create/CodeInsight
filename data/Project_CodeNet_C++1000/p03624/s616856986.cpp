#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  string s;
  cin >> s;
  
  vector<char> ch(s.size());
  for(int i=0; i<s.size(); i++){
    ch[i] = s[i];
  }
  sort(ch.begin(),ch.end());
  
  vector<int> tf(26);
  for(int i=0; i<26; i++){
    tf[i] = 0;
  }
    
  for(int i=0; i<s.size(); i++){
    tf[ch[i]-'a'] = 1;
  }
  
  int count = 0;
  
  for(int i=0; i<26; i++){
    if(tf[i] == 1){
      count++;
    }
  }
  
  char c = 0;
  if(count == 26){
    cout << "None" << endl;
  }
  else{
    for(int i=0; i<26; i++){
     if(tf[i] == 0){
       c = 97 + i;
      cout << c << endl;
      break;
     }
    }
  }
  return 0;
}
