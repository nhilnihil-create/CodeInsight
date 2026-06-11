#include <iostream>
#include <string>
using namespace std;

int main(){
  string data1,data2;
  cin>>data1;
  cin>>data2;
  int flag=1;
  if(data1.size()>data2.size()){
    cout<<"GREATER"<<endl;
  }
  else if(data1.size()<data2.size()){
    cout<<"LESS"<<endl;
  }
  else if(data1.size()==data2.size()){
    for(int i=0;i<data1.size();i++){
      if(data1[i]>data2[i]){
        flag=0;
        cout<<"GREATER"<<endl;
        break;
      }
      else if(data1[i]<data2[i]){
        flag=0;
        cout<<"LESS"<<endl;
        break;
      }
    }
    if(flag==1){
      cout<<"EQUAL"<<endl;
    }
  }
}