#include<bits/stdc++.h>
using namespace std;
int main(){
  string x,y;
  cin>>x>>y;
  int l=x.length(),m=y.length(),j;
  if(l<m) cout<<"LESS"<<endl;
  else if(l>m) cout<<"GREATER"<<endl;
  else{
    for(j=0;j<l;j++){
      if(x.at(j)<y.at(j)){
        cout<<"LESS"<<endl;
        break;
      }
      else if(x.at(j)>y.at(j)){
        cout<<"GREATER"<<endl;
        break;
      }
    }
    if(j==l) cout<<"EQUAL"<<endl;
  }
}