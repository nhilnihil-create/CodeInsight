#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  bool ad=false;
  for(int i=0;i<s.size();i++){
    for(int j=i+1;j<s.size();j++){
      if(s[i]==s[j]){
        ad=true;
        break;
      }
    }
  }
  if(ad) cout<<"no"<<endl;
  else cout<<"yes"<<endl;
}
     
      
      
      
    
