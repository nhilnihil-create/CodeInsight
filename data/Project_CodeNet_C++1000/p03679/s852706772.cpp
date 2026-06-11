#include<iostream>
using namespace std;

int main(){
  int X,A,B;
  cin>>X>>A>>B;
  if(A-B>=0){
    cout<<"delicious"<<endl;
  }else{
    int d=B-A;
    if(d<=X){
      cout<<"safe"<<endl;
    }else{
      cout<<"dangerous"<<endl;
    }
  }
  return 0;
}
