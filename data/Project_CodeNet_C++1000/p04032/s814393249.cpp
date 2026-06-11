#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  string s;
  cin >> s;
  bool ch=true;
  
  rep(i,s.size()-1){
    if(s.at(i)==s.at(i+1)){
      cout<<i+1<<" "<<i+2<<endl;
      ch=false;
      break;
    }
  }
 if(ch){
   rep(i,s.size()-2){
     if(s.at(i)!=s.at(i+1)&&s.at(i)==s.at(i+2)){
      cout<<i+1<<" "<<i+3<<endl;
      ch=false;
      break;
    }
  }
 }
  if(ch){
   cout<<-1<<" "<<-1<<endl;
 }
 
}

