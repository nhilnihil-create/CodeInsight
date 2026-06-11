#include<bits/stdc++.h>
using namespace std;
int main(){
  int a[3],i,num5=0,num7=0;
  cin>>a[0];
  cin>>a[1];
  cin>>a[2];
  for(i=0;i<3;i++){
    if(a[i]==5){num5++;}
    if(a[i]==7){num7++;}
  }
  if(num5==2&&num7==1){cout<<"YES"<<endl;}
  else{cout<<"NO"<<endl;}
}
