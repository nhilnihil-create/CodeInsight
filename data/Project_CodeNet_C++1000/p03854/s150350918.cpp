#include<bits/stdc++.h>
using namespace std;

int main(){
  string t;
  string s[4]={"dream","dreamer","erase","eraser"};
  cin>>t;
  reverse(t.begin(),t.end());
  for(int i=0;i<4;i++){
    reverse(s[i].begin(),s[i].end());
  }
  for(int i=0;i<t.size();){
    bool flag=false;
    for(int j=0;j<4;j++){
      string x=s[j];
      if(t.substr(i,x.size())==x) {
        flag=true;
        i+=x.size();
      }
    }
    if(!flag){cout<<"NO"; return 0;}
  }
  cout<<"YES";
}
