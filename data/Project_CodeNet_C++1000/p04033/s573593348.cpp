#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b;
  cin>>a>>b;
  if(b>0 && a>0)cout<<"Positive";
  else if(a<=0 && b>=0)cout<<"Zero";
  else{
  	if((b-a+1)%2==0)cout<<"Positive";
    else cout<<"Negative";
  }
}