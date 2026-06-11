#include<iostream>
using namespace std;
int main(){
  int a,b,c,d;
  while(cin>>a>>b>>c>>d){
    cout<<max(a*b,c*d)<<endl; 
  }
  return 0;
}