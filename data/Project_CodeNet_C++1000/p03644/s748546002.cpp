#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin>>N;
  if(N>=64){
    cout<<64;
  }else if(N>=32){
    cout<<32;
  }else if(N>=16){
    cout<<16;
  }else if(N>=8){
    cout<<8;
  }else if(N>=4){
    cout<<4;
  }else if(N>=2){
    cout<<2;
  }else if(N>=1){
    cout<<1;
  }
}