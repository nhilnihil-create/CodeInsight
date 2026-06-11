#include<iostream>
using namespace std;

int Daikei(int a,int b,int h){
      return (a+b)*h/2;
  }

int main(){
  int a,b,h;
  cin>>a>>b>>h;
  
  cout<<Daikei(a,b,h)<<endl;
  
}