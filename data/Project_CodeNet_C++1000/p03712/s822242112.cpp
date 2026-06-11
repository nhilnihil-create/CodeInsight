#include<iostream>
#include<string>
using namespace std;
int main(){

  int H,W;
  cin>>H>>W;
  string data[H];
  for(int i=0;i<=H-1;i++){
  
    cin>>data[i];
  }
  for(int i=1;i<=W+2;i++){
  
    cout<<"#";
  }
  cout<<endl;
  for(int i=0;i<=H-1;i++){
  
    cout<<"#"<<data[i]<<"#"<<endl;
  }
  for(int i=1;i<=W+2;i++){
  
    cout<<"#";
  }
  cout<<endl;
  return 0;
}