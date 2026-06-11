#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;cin>>a>>b;
  if(a<2)a+=13;
  if(b<2)b+=13;
  cout<<(a>b?"Alice":a<b?"Bob":"Draw");
}