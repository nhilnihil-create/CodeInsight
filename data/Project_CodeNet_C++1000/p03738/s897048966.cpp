#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b;
  cin>>a>>b;
  if(a.size()>b.size()){
    cout<<"GREATER"<<endl;
    return 0;
  }else if(a.size()<b.size()){
    cout<<"LESS"<<endl;
    return 0;
  }else{
    for(int i=0;i<a.size();i++){
      int kazua=a[i]-'0';
      int kazub=b[i]-'0';
      if(kazua==kazub){
        continue;
      }else if(kazua>kazub){
        cout<<"GREATER"<<endl;
        return 0;
      }else{
        cout<<"LESS"<<endl;
        return 0;
      }
    }
  }
  cout<<"EQUAL"<<endl;
  return 0;
}
