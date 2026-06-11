#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int x=1;
  if(a!=b){
  x++;
  if(b!=c&&a!=c){
  x++;
  }
  }
  else{
  if(a!=c){
  x++;
  }
  }
  cout<<x<<endl;
}
