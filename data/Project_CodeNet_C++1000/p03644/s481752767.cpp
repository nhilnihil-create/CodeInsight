#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  if(64<=N&&N<=100){
    cout<<"64"<<endl;
  }
   if(32<=N&&N<64){
     cout<<"32"<<endl;
   }
  if(16<=N&&N<32){
     cout<<"16"<<endl;
   }
  if(8<=N&&N<16){
     cout<<"8"<<endl;
   }
  if(4<=N&&N<8){
     cout<<"4"<<endl;
   }
  if(2<=N&&N<4){
     cout<<"2"<<endl;
   }
  if(1<=N&&N<2){
     cout<<"1"<<endl;
   }
}