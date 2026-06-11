#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if(a==b){
    if(b==c){
      cout<<1<<endl;
    }
    else{
      cout<<2<<endl;
    }
  }
  else if(a!=b){
    if(b==c){
      cout<<2<<endl;
    }
    else if(a==c){
      cout<<2<<endl;
    }
    else {
      cout<<3<<endl;
    }
  }
}