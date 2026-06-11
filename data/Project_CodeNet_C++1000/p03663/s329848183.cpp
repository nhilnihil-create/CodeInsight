#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int A=0;
  while(++A){
    cout<<"? 1";
    for(int i=1;i<A;i++)cout<<0;
    cout<<'\n';
    fflush(stdout);
    char c;
    cin>>c;
    if(c=='N')break;
    if(A>10){
      A=0;
      while(++A){
        cout<<"? 2";
        for(int i=1;i<A;i++)cout<<0;
        cout<<'\n';
        fflush(stdout);
        char c;
        cin>>c;
        if(c=='Y'){
          cout<<"! 1";
          for(int i=0;i<A-1;i++)cout<<0;
          cout<<'\n';
          return 0;
        }
      }
    }
  }
  A--;
  int ok=10,ng=1;
  for(int i=1;i<A;i++)ok*=10,ng*=10;
  while(ok-ng>1){
    int n=(ok+ng)/2;
    cout<<"? "<<n*10<<'\n';
    fflush(stdout);
    char c;
    cin>>c;
    if(c=='Y')ok=n;
    else ng=n;
  }
  cout<<"! "<<ok<<'\n';
}