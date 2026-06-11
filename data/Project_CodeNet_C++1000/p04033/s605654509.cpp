#include<iostream>
using namespace std;

int main(){
  int a,b;cin>>a>>b;
  if(a<=0&&b>=0){
    cout<<"Zero"<<endl;
    return 0;
  }else if(b<0&&(b-a+1)&1){
    cout<<"Negative"<<endl;
    return 0;
  }else{
    cout<<"Positive"<<endl;
    return 0;
  }
}