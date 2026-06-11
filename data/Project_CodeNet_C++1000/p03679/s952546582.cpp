#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,a,b;
  cin>>x>>a>>b;
  if(a>=b){
    cout<<"delicious";
  }
  else if(a+x>=b){
    cout<<"safe";
  }
  else if(b>a+x){
    cout<<"dangerous";
  }
}