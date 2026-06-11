#include<bits/stdc++.h>
using namespace std;


int main(){
  string s;
  cin >> s;
  if(s.size()==2){
    if(s[0]==s[1]) cout << "1" << " " << "2" << endl;
    else cout << "-1" << " " << "-1" << endl;
    return 0;
  }

  for(int i=0;i<s.size()-2;++i){
    for(int al='a';al<='z';++al){
      int cnt=0;
      for(int j=0;j<3;++j){
        if(s[i+j]==al)cnt++;
      }
      if(cnt>=2){
        cout << i+1 << " " << i+3 << endl;
        return 0;
      }
    }
  }
  cout << "-1" << " " << "-1" << endl;
  return 0;
}
