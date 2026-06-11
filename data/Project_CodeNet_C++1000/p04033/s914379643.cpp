#include<bits/stdc++.h>
using namespace std;
int main(void){
  int a,b;
  string ans;
  cin>>a>>b;
  if(0<a && a<=b){
    ans="Positive";
  }else if(a<=b && b<0){
    if((b-a+1)%2==0){
      ans="Positive";
    }else{
      ans="Negative";
    }
  }else{
    ans="Zero";
  }
  cout<<ans<<endl;
}