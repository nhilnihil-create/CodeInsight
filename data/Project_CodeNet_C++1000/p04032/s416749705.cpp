#include<bits/stdc++.h>
using namespace std;
bool unb(string s){
  set<char>se;
  se.insert(s[0]);
  se.insert(s[1]);
  se.insert(s[2]);
  if(se.size()<=2)return true;
  else return false;
}

int main(){
  string s;
  cin >> s;
  int n = s.length();
  bool chk = false;
  int left = -1;
  for(int i = 0;i<n-2;i++){
    if(unb(s.substr(i,3))){
      chk = true;
      left = i+1;
      break;
    }
  }
  if(n==2 && s[0]==s[1])cout << 1 << " "<<2 << endl;
  else if(chk){
    cout << left << " " << left+2 << endl;
  }else cout << -1 << " "<<-1<<endl;
}
