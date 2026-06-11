#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin>>S;
  int a=S.size();
  int b=0;
  for(int i=0;i<a-1;i++){
    for(int j=i+1;j<a;j++){
      if(S.at(i)==S.at(j)){
        cout<<"no"<<endl;
        b=1;
        break;
      }
      if(b==1)
        break;
    }
    if(b==1)
      break;
  }

 if(b==0)
   cout<<"yes"<<endl;
  
}