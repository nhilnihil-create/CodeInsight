#include <iostream>

using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  if(a==1){
    if(b==1){
      cout<<"Draw"<<endl;
      return 0;
    }
    cout<<"Alice"<<endl;
    return 0;
  }else if(b==1){
    cout<<"Bob"<<endl;
    return 0;
  }
  if(a>b){
    cout<<"Alice"<<endl;
    return 0;
  }else if(a<b){
    cout<<"Bob"<<endl;
    return 0;
  }else{
    cout<<"Draw"<<endl;
  }
  return 0;
}