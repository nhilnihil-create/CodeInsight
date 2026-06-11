#include<bits/stdc++.h>
using namespace std;
int main(){
  int sx,sy,tx,ty,dx,dy,j;
  cin>>sx>>sy>>tx>>ty;
  dx=tx-sx;
  dy=ty-sy;
  for(j=0;j<dx;j++) cout<<'R';
  for(j=0;j<dy;j++) cout<<'U';
  for(j=0;j<dx;j++) cout<<'L';
  for(j=0;j<=dy;j++) cout<<'D';
  for(j=0;j<=dx;j++) cout<<'R';
  for(j=0;j<=dy;j++) cout<<'U';
  cout<<"LU";
  for(j=0;j<=dx;j++) cout<<'L';
  for(j=0;j<=dy;j++) cout<<'D';
  cout<<'R'<<endl;
}