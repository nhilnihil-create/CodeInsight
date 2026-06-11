#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
  string T[4]={"dream","dreamer","erase","eraser"};
  string S;
  cin>>S;
  reverse(S.begin(),S.end());
  for(int i=0;i<4;i++){
    reverse(T[i].begin(),T[i].end());
  }
  bool ans2 =true;
  for(int i=0;i<S.size();){
    bool ans=false;
    for(int j =0;j<4;j++){
      string tmp=T[j];
      if(S.substr(i,tmp.size())==tmp){
        ans=true;
        i+=tmp.size();
      }
    }
    if(!ans){
      ans2=false;
      break;
    }
  }
  
  if(ans2) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}

  
  