#include <bits/stdc++.h>
using namespace std;

int main(){
int sx ,sy, tx ,ty;
  cin>>sx>>sy>>tx>>ty;
  int a,b;
  a=tx-sx;
  b=ty-sy;
  for(int i=0;i<a;i++){
cout<<"R";
  }
  for(int i=0;i<b+1;i++){
cout<<"U";
  }
  for(int i=0;i<a+1;i++){
cout<<"L";
  }
  for(int i=0;i<b+1;i++){
cout<<"D";
  }
  cout<<"R"<<"D";
   for(int i=0;i<a+1;i++){
cout<<"R";
  }
   for(int i=0;i<b+1;i++){
cout<<"U";
  }
  for(int i=0;i<a+1;i++){
cout<<"L";
  }
    for(int i=0;i<b;i++){
cout<<"D";
  }
  cout<<endl;
}
    
