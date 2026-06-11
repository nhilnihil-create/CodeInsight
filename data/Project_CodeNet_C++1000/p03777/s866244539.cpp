#include<iostream>
using namespace std;
int main(){
  char a,b;
  cin>>a>>b;
  if(a=='H'){
    if(b=='H')
      cout<<"H"<<endl;
    if(b=='D')
      cout<<"D"<<endl;
  }
  if(a=='D'){
    if(b=='H')
      cout<<"D"<<endl;
    if(b=='D')
      cout<<"H"<<endl;
  }
}