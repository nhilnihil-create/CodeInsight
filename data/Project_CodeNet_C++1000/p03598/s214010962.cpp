#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k,x,y=0;
  int a=0,b=0;
  cin >>n>>k;
  for(int i=0;i<n;i++){
    cin >>x;
    b=k-x;
    a=x;
    if(a<=b){
      y+=2*a;
    }
    else{
      y+=2*b;
    }
  }
  cout <<y<<endl;
}