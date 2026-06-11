#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int left,cnt;
  left=0;
  cnt=0;
  for(int i=0;i<s.size();++i){
    if(s[i]=='(') ++cnt;
    else{
      if(cnt==0) ++left;
      else --cnt;
    }
  }
  int right=cnt;
  string ans="";
  for(int i=0;i<left;++i) ans+='(';
  ans+=s;
  for(int i=0;i<right;++i) ans+=')';

  cout << ans << endl;
  return 0;
}
