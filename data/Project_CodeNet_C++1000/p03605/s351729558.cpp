#include<iostream>
using namespace std;
int main(){
  int a,b;
  cin>>a;
  if(a%10==9||a/10==9)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}