#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)


int main(){
  int a,b;
  cin>>a>>b;
  int num=0;
  int coun=0;
  for(int i=a;i<=b;i++){
    if(i<0){
      coun++;
    }
  }
  if(a<=0&&b>=0){
    cout<<"Zero"<<endl;
  }
  else if(coun%2==0){
    cout<<"Positive"<<endl;
  }
  else {
    cout<<"Negative"<<endl;
  }
}
    
    
  
      