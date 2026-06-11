#include <bits/stdc++.h>
using namespace std;

int main(){
  int sx,sy,tx,ty;
  cin>>sx>>sy>>tx>>ty;
  int x=tx-sx,y=ty-sy;
  for(int i=0;i<x;i++)
    cout<<'R';
  for(int i=0;i<y;i++)
    cout<<'U';
  for(int i=0;i<x;i++)
    cout<<'L';
  for(int i=0;i<y;i++)
    cout<<'D';
  cout<<'D';
  for(int i=0;i<=x;i++)
    cout<<'R';
  for(int i=0;i<=y;i++)
    cout<<'U';
  cout<<"LU";
  for(int i=0;i<=x;i++)
    cout<<'L';
  for(int i=0;i<=y;i++)
    cout<<'D';
  cout<<'R';
}