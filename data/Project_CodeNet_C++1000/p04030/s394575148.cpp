#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  string t;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '1'){
      t.push_back('1');
    }else if(s[i] == '0'){
      t.push_back('0');
    }else{
      if(t.size() != 0){
        t.pop_back();
      }
    }
  }
  cout << t << endl;
}