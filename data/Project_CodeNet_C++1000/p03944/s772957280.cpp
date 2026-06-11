#include <bits/stdc++.h>
using namespace std;

int main(){
  int W,H,N;
  cin>>W>>H>>N;
  vector<bool> A(W,true),B(H,true);
  for(int i=0;i<N;i++){
    int x,y,a;
    cin>>x>>y>>a;
    if(a==1)
      for(int i=0;i<x;i++)
        A.at(i)=false;
    else if(a==2)
      for(int i=x;i<W;i++)
        A.at(i)=false;
    else if(a==3)
      for(int i=0;i<y;i++)
        B.at(i)=false;
    else
      for(int i=y;i<H;i++)
        B.at(i)=false;
  }
  int x=0,y=0;
  for(bool b:A)
    if(b)
      x++;
  for(bool b:B)
    if(b)
      y++;
  cout<<x*y<<endl;
}