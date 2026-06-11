#include<iostream>
using namespace std;
int main(){
  int a[3],i,b=0,j;
  for(i=0;i<3;i++){
    cin>>a[i];
  }
  for(i=0;i<2;i++){
    for(j=i+1;j<3;j++){
      if(a[i]!=a[j]){
        b++;
      }
    }
  }
  if(b==0)
    b=1;
  
  cout<<b;
  
  return 0;
}
