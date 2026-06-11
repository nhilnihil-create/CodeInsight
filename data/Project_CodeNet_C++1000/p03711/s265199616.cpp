#include<bits/stdc++.h>
using namespace std;

int main(){
  int x,y;
  cin >> x >> y;
  if(x==2){
    x=28;
  }else if(x==4||x==6||x==9||x==11){
    x=30;
  }else{
    x=31;
  }
  if(y==2){
    y=28;
  }else if(y==4||y==6||y==9||y==11){
    y=30;
  }else{
    y=31;
  }
  
  if(x==y){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}