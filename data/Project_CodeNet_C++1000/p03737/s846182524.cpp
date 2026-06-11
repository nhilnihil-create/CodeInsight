#include<bits/stdc++.h>
using namespace std;
const string s="abcdefghijklmnopqrstuvwxyz";
const string S="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  string ss[3];
  cin>>ss[0]>>ss[1]>>ss[2];
  string ans;
  for(int i=0;i<3;i++){
    for(int j=0;j<26;j++){
      if(ss[i].at(0)==s[j]){
        ans+=S[j];
      }
    }
  }
  cout<<ans<<endl;
}
