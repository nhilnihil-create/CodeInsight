#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
int main(){
  int N,x;
  cin>>N>>x;
  if(x==1||x==N*2-1) cout<<"No"<<endl;
  else{
    cout<<"Yes"<<endl;
    if(x==2){
     for(int i=0;i<N*2-1;i++){
       if(i<N-2) cout<<i+3<<endl;
       else if(i<N+2){
         if(i==N-2) cout<<N*2-1<<endl;
         if(i==N-1) cout<<2<<endl;
         if(i==N) cout<<1<<endl;
         if(i==N+1) cout<<N*2-2<<endl;
       }
       else cout<<i-1<<endl;
     }
    }
    else{
      for(int i=0;i<N*2-1;i++){
        if(i<N-2){
          if(i+3<x) cout<<i+3<<endl;
          else cout<<i+4<<endl;
        }
        else if(i<N+2){
          if(i==N-2) cout<<1<<endl;
          if(i==N-1) cout<<x<<endl;
          if(i==N) cout<<N*2-1<<endl;
          if(i==N+1) cout<<2<<endl;
        }
        else{
          if(i-1<x) cout<<i-1<<endl;
          else cout<<i<<endl;
        }
      }
    }
  }
  return 0;
}