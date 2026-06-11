#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;cin>>S;
  int l=S.size();
  vector<bool> A(26,false);
  for(int i=0;i<l;i++) A.at(S.at(i)-'a')=true;
  int m=-1;
  for(int j=0;j<26;j++){
    if(!A.at(j)){
      m=j;
      break;
    }
  }
  if(m==-1) cout<<"None"<<endl;
  else cout<<(char)('a'+m)<<endl;
}
