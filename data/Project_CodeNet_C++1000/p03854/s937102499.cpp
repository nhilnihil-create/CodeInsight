#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  string s;
  cin>>s;
  bool ans=1;
  int i = s.size()-1;
  for(int i = s.size()-1; i>=0; i--){
    if(s[i]=='r'){
      if(i-5>=0 && s.substr(i-5,6)=="eraser"){
        i-=5;
      }else if(i-6>=0 && s.substr(i-6,7)=="dreamer"){
        i-=6;
      }else{
        ans=0;
      }
    }else if(s[i]=='m'){
      if(i-4>=0 && s.substr(i-4,5)=="dream"){
        i-=4;
      }
    }else if(s[i]=='e'){
      if(i-4>=0 && s.substr(i-4,5)=="erase"){
        i-=4;
      }
    }else{
      ans=0;
    }
  }
  if(ans) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

