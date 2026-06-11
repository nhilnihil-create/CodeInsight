#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int a,b;
  cin>>a>>b;
  if(a>0 && b>0){
    cout<<"Positive";
  }else if(a<=0 && b>=0){
    cout<<"Zero";
  }else {
    int n=b-a;
    if(n%2==0){
      cout<<"Negative";
    }else{
      cout<<"Positive";
    }
  }




}

