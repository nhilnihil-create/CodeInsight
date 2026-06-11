#include<iostream>
using namespace std;
int main(){
  char a,b;
  cin>>a>>b;
  if((a=='H'&&b=='H')||(a=='D'&&b=='D'))
    cout<<"H";
  else
    cout<<"D";
  return 0;
}