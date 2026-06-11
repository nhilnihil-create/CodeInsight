#include<iostream>
using namespace std;
int main(){
  
  int a;
  cin>>a;
  bool hasNine=false;
  while(a){
    int d=a%10;
    if(d==9)
    {
      hasNine=true;
      break;
    }
    a/=10;
  }
 	
  if(hasNine) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}