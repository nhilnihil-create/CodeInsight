#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  bool a[26];
  for(int i = 0; i < 26; i++){
    a[i] = false;
  }
  for(int i = 0; i < s.size(); i++){
    a[s[i] - 'a'] = true;
  }
  for(int i = 0; i < 26; i++){
    if(a[i] == false){
      cout << (char)(i+'a') << endl;
      return 0;
    }
  }
  cout << "None" << endl;
  return 0;
}