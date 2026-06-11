#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y;
  cin>>x>>y;
  int gx=0;
  int gy=0;
  if(x==4||x==6||x==9||x==11){
    gx=1;}
  if(y==4||y==6||y==9||y==11){
    gy=1;}
if(x==2){gx=2;}
  if(y==2){gy=2;}
  
  if(gx==gy){cout<<"Yes"<<endl;}
  else if(gx!=gy){cout<<"No"<<endl;}
}
