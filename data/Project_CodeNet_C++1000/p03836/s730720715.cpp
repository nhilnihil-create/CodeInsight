#include<bits/stdc++.h>
using namespace std;
int main(){
  int sx,sy,tx,ty;
  cin>>sx>>sy>>tx>>ty;
  int x=tx-sx;
  int y=ty-sy;
  string f;
  string b;
  for(int i=0;i<x;i++){
    f+='R';
    b+='L';
  }
  for(int i=0;i<y;i++){
    f+='U';
    b+='D';
  }
  cout<<f<<b<<"DR"<<f<<"ULUL"<<b<<"DR"<<endl;
}