#include<iostream>
using namespace std;
int main(){

  int X,A,B;
  cin>>X>>A>>B;
  int time=A-B;
  if(time>=0){
  
    cout<<"delicious";
    return 0;
  }
  else if(time*-1<=X){
  
    cout<<"safe";
    return 0;
  }
  else{
  
    cout<<"dangerous";
    return 0;
  }
}