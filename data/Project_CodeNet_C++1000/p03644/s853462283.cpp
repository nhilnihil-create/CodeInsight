#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  int ans=1;
  int X=2;
  while(X<101){
    if(N>=X) ans*=2;
    X*=2;
  }
  cout<<ans<<endl;
}
  
  
