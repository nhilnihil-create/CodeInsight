#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;

int main(){
  string s, t, d;
  int a=3;
  cin >> s;
  reverse(s.begin(),s.end());
  d = s;
  while(s.size()>0){
    if(s[0]=='r' || s[1]=='e'){
      if(s[2]=='m'){
        t+="remaerd";
        s.erase(0, 7);
      }else if(s[2]=='s'){
        t+="resare";
        s.erase(0, 6);
      }else{
        break;
      }
    }else if(s[0]=='e'){
      if(s[1]=='s'){
        t+="esare";
        s.erase(0, 5);
      }
    }else if(s[0]=='m'){
      if(s[1]=='a'){
        t+="maerd";
        s.erase(0, 5);
      }
    }
  }
  cout << (t==d?"YES":"NO") << endl;
  return 0;
}
