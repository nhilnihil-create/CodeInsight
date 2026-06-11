#include<bits/stdc++.h>
using namespace std;

int main(){
  int x,y;
  cin >> x >> y;
  bool a=false;
  if(x==4 || x==6 || x==9){
    if(y==6 || y==9 || y==11){
      a=true;
    }
  }
  else if(x==1 || x==3 || x==5 || x==7 || x==10){
    if(y==3 || y==5 || y==7 || y==8 || y==10){
      a=true;
    }
  }
  if(a){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}