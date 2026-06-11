#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int a_index = 0, z_index = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'A'){
      a_index = i;
      break;
    }
  }
  for(int i = s.size(); i >= 0; i--){
    if(s[i] == 'Z'){
      z_index = i;
      break;
    }
  }
  cout << z_index - a_index + 1 << endl;
  return 0;
}